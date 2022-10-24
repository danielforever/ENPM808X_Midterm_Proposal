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
Detector::Detector(VideoCapture Cap, const string& Inputstype) {
  this->cap = Cap;
  this->inputStype = Inputstype;
  isInitialized = true;
  DetectorSystem();
}
void Detector::inputClass() {}

void Detector::drawPred(int classId, float conf, int left, int top, int right,
                        int bottom, Mat& frame) {}

vector<String> Detector::getOutputsNames(const Net& net) {
  static vector<String> names;

  return names;
}
/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem() { 
    VideoWriter video;
    Mat frame, blob;
    Net net = readNetFromDarknet(modelConfiguration, modelWeights);

    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);
    cout<< this->inputStype<<endl;
    try {
        if (this->inputStype == "image")
        {
            this->outputFile = "result.jpg";
        }
        else if (this->inputStype == "video")
        {
            this->outputFile = "result.avi";
        }
        else cap.open("stream");
        
    }
    catch(...) {
        cout << "Error: Did not detect any valid input file." << endl;
        return 0;
    }
    if (this->inputStype == "image") {
        video.open(this->outputFile, VideoWriter::fourcc('M','J','P','G'), 28, Size(cap.get(CAP_PROP_FRAME_WIDTH), cap.get(CAP_PROP_FRAME_HEIGHT)));
    }

    namedWindow("Yolov3", WINDOW_NORMAL);
    Size newSize;

    
    while (waitKey(1) < 0)
    {
        cap >> frame;

        if (frame.empty()) {
            waitKey(5000);
            break;
        }

        cv::cvtColor(frame, frame, COLOR_BGR2RGB);

        newSize = resize(frame);
        cout << "After Resize:" << newSize.width << " " << newSize.height << endl;
        cout << "Before Resize:" << frame.cols << " " << frame.rows << endl;

        blobFromImage(frame, blob, 1/255.0, Size(inputWidth, newSize.height), Scalar(0,0,0), true, false);
        
        net.setInput(blob);
        
        vector<Mat> frameResult;
        Mat resultFrame;
        static vector<String> names;
        if (names.empty()){
        
        vector<int> outLayers = net.getUnconnectedOutLayers();
        
        vector<String> layersNames = net.getLayerNames();
        
        names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i)
        names[i] = layersNames[outLayers[i] - 1];
    }
        net.forward(frameResult, getOutputsNames(net));
        
        //DrawBoundingBox(frame, frameResult);
        
        frame.convertTo(resultFrame, CV_8U);
        cv::cvtColor(resultFrame,resultFrame, COLOR_RGB2BGR);
        if (inputStype == "image") imwrite(this->outputFile, resultFrame);
        else video.write(resultFrame);
        
        imshow("Yolov3", frame);
        
    }

    cap.release();
    if (!(inputStype == "image")) video.release();
   
    return 0; }
Detector::~Detector() { isInitialized = false; }

/**
 * @brief
 *
 * @return true
 * @return false
 */

int Detector::CoordinateTransform() { return 0; }

void Detector::DrawBoundingBox(Mat& frame,
                               const vector<Mat>& frameResult) {}

Size Detector::resize(Mat frame) { 
    int width = frame.cols;
    int height = frame.rows;
    float yoloPixel = 416.0;
    float maxPixel = max(width, height);
    float ratio = yoloPixel/maxPixel;
    int resizeWidth = int(((416 - int(round(width * ratio))) % 32 )/2);
    int resizeheight = int(((416 - int(round(height * ratio))) % 32 )/2);
    int top = int(round(resizeheight - 0.1));
    int bottom = int(round(resizeheight + 0.1));
    int left = int(round(resizeWidth - 0.1));
    int right = int(round(resizeWidth + 0.1));

    cv::resize(frame, frame, cv::Size(416, 416), 0, 0, 1);
    Scalar value(127.5, 127.5, 127.5);
    cv::copyMakeBorder(frame, frame, top, bottom, left, right, cv::BORDER_CONSTANT, value);
    return frame.size(); 
    }
