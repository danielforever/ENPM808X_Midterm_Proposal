/**
 * @file detector.hpp
 * @author Shantanu Aman Po-Yu
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../../include/detector.hpp"

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>

/**
 * @brief Construct a new Detector:: Detector object
 *
 */
Detector::Detector(cv::VideoCapture Cap, const std::string& Inputstype) {
  this->cap = Cap;
  this->inputStype = Inputstype;
  this->net = cv::dnn::readNetFromDarknet(modelConfiguration,
                                                          modelWeights);
  this->net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
  this->net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
  if (this->inputStype == "image") {
    std::cout << "suceess read image." << std::endl;
    this->outputFile = "result.jpg";
  } else {
    std::cout << "suceess read video." << std::endl;
    this->outputFile = "result.avi";
  }
  if (this->inputStype != "image") {
    std::cout << "image check!" << std::endl;
    this->video.open(this->outputFile,
                     cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), 28,
                     cv::Size(this->cap.get(cv::CAP_PROP_FRAME_WIDTH),
                              this->cap.get(cv::CAP_PROP_FRAME_HEIGHT)),
                     true);
    std::cout << "image check!" << std::endl;
  }
}

void Detector::getOutputsNames() {
  std::ifstream in(this->cocoFile.c_str());
  std::string str;
  while (getline(in, str)) {
    if (str.size() > 0) this->classes.push_back(str);
  }
  std::cout << "load coco.names" << std::endl;
}

cv::Size Detector::boxSize() {
  int width = this->frame.cols;
  int height = this->frame.rows;
  float ratio = static_cast<float>(416) / std::max(width, height);
  this->widthRatio = static_cast<int>(round(width * ratio));
  this->heightRatio = static_cast<int>(round(height * ratio));
  int newWidth = ((416 - this->widthRatio) % 32) / 2;
  int newHeight = ((416 - this->heightRatio) % 32) / 2;
  int left = static_cast<int>(round(newWidth - 0.1));
  int right = static_cast<int>(round(newWidth + 0.1));
  int top = static_cast<int>(round(newHeight - 0.1));
  int bottom = static_cast<int>(round(newHeight + 0.1));

  cv::resize(this->frame, this->frame,
             cv::Size(this->widthRatio, this->heightRatio), 0, 0, 1);
  cv::Scalar value(127.5, 127.5, 127.5);
  cv::copyMakeBorder(this->frame, this->frame, top, bottom, left, right,
                     cv::BORDER_CONSTANT, value);
  return this->frame.size();
}

void Detector::drawPred(int left, int right, int top, int bottom, int idname,
                        double x, double y, double z) {
  rectangle(this->frame, cv::Point(left, top), cv::Point(right, bottom),
            cv::Scalar(255, 178, 50), 3);
  std::cout << "bounding box check2" << std::endl;

  std::string label1 = "Person" + std::to_string(idname);
  std::string label2 = "( " + std::to_string(x) + "," + std::to_string(y) +
                       "," + std::to_string(z) + ")";
  int baseLine;
  cv::Size labelSize =
      cv::getTextSize(label2, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
  top = std::max(top, labelSize.height);
  rectangle(this->frame, cv::Point(left, top - round(1.5 * labelSize.height)),
            cv::Point(left + round(1.5 * labelSize.width), top + baseLine),
            cv::Scalar(255, 255, 255), cv::FILLED);
  putText(this->frame, label1, cv::Point(left, top - 10),
          cv::FONT_HERSHEY_SIMPLEX, 0.30, cv::Scalar(0, 0, 0), 1);
  putText(this->frame, label2, cv::Point(left, top), cv::FONT_HERSHEY_SIMPLEX,
          0.30, cv::Scalar(0, 0, 0), 1);
}

/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const cv::Mat& Frame) {
  this->frame = Frame;
  cv::Mat blob;
  std::cout << " Detect system on" << std::endl;

  cv::cvtColor(this->frame, this->frame, cv::COLOR_BGR2RGB);
  this->newSize = this->boxSize();

  cv::dnn::blobFromImage(
      this->frame, blob, 1 / 255.0,
      cv::Size(this->inputWidth, this->newSize.height), cv::Scalar(0, 0, 0),
      true, false);
  this->net.setInput(blob);

  if (this->names.empty()) {
    std::vector<int> outLayers = this->net.getUnconnectedOutLayers();

    std::vector<std::string> layersNames = this->net.getLayerNames();

    this->names.resize(outLayers.size());
    for (size_t i = 0; i < outLayers.size(); ++i)
      this->names[i] = layersNames[outLayers[i] - 1];
  }
  this->net.forward(this->frameResult, this->names);
  for (size_t i = 0; i < this->frameResult.size(); ++i) {
    float* result = reinterpret_cast<float*>(this->frameResult[i].data);
    for (int j = 0; j < this->frameResult[i].rows;
         ++j, result += this->frameResult[i].cols) {
      cv::Mat scores =
          this->frameResult[i].row(j).colRange(5, this->frameResult[i].cols);
      cv::Point classIdPoint;
      double confidence;
      cv::minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
      if (confidence > this->confThreshold && classIdPoint.x == 0) {
        int centerX = static_cast<int>(result[0] * frame.cols);
        int centerY = static_cast<int>(result[1] * frame.rows);
        int width = static_cast<int>(result[2] * frame.cols);
        int height = static_cast<int>(result[3] * frame.rows);
        int left = centerX - width / 2;
        int top = centerY - height / 2;
        int right = centerX + width / 2;
        int bottom = centerY + height / 2;
        this->classIds.push_back(classIdPoint.x);
        std::cout << "centerX: " << centerX << std::endl;
        std::cout << "centerY: " << centerY << std::endl;
        this->confidences.push_back(confidence);
        this->boxes.push_back(cv::Rect(left, top, width, height));
      }
    }
  }
  cv::dnn::NMSBoxes(this->boxes, this->confidences, this->confThreshold,
                    this->nmsThreshold, this->index);
  for (auto i : this->index) this->trackerBoxes.push_back(this->boxes[i]);

  return true;
}

Detector::~Detector() { isInitialized = false; }

int Detector::DrawBoundingBox() {
  for (size_t i = 0; i < this->index.size(); ++i) {
    std::cout << "check times" << std::endl;
    int idx = this->index[i];
    cv::Rect box = this->boxes[idx];
    drawPred(box.x, box.x + box.width, box.y, box.y + box.height,
             this->objectTrackingid[i], this->roboticRefFrame[i].at(0),
             this->roboticRefFrame[i].at(1), this->roboticRefFrame[i].at(2));
  }

  return 0;
}

cv::Mat Detector::CleanAndDisplay() {
  cv::Mat detectedFrame;
  this->frame.convertTo(detectedFrame, CV_8U);
  cv::cvtColor(detectedFrame, detectedFrame, cv::COLOR_RGB2BGR);
  if (this->inputStype == "image")
    cv::imwrite(this->outputFile, detectedFrame);
  else
    this->video.write(detectedFrame);
  cv::resize(detectedFrame, detectedFrame,
             cv::Size(detectedFrame.cols * 1.5, detectedFrame.rows * 1.5), 0, 0,
             1);
  
  this->confidences.clear();
  this->boxes.clear();
  this->classIds.clear();
  this->trackerBoxes.clear();
  this->objectTrackingid.clear();
  return detectedFrame;
}
