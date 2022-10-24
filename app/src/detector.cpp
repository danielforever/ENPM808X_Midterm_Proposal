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
    cout<< this->inputtype<<endl;
    try {
        if (this->inputtype == "image")
        {
            this->outputFile = "result.jpg";
        }
        else if (this->inputtype == "video")
        {
            this->outputFile = "result.avi";
        }
        else cap.open("stream");
        
    }
    catch(...) {
        cout << "Error: Did not detect any valid input file." << endl;
        return 0;
    }
    if (this->inputtype == "image") {
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

        blobFromImage(frame, blob, 1/255.0, Size(inpWidth, newSize.height), Scalar(0,0,0), true, false);
        
        net.setInput(blob);
        
        vector<Mat> frameResult;
        static vector<String> names;
        if (names.empty()){
        
        vector<int> outLayers = net.getUnconnectedOutLayers();
        
        //get the names of all the layers in the network
        vector<String> layersNames = net.getLayerNames();
        
        // Get the names of the output layers in names
        names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i)
        names[i] = layersNames[outLayers[i] - 1];
    }
        net.forward(frameResult, getOutputsNames(net));
        
        DrawBoundingBox(frame, frameResult);
        
            
        // Write the frame with the detection boxes
        Mat detectedFrame;
        frame.convertTo(detectedFrame, CV_8U);
        cv::cvtColor(detectedFrame,detectedFrame, COLOR_RGB2BGR);
        if (inputtype == "image") imwrite(this->outputFile, detectedFrame);
        else video.write(detectedFrame);
        
        imshow("Yolov3", frame);
        
    }

    cap.release();
    if (!(inputtype == "image")) video.release();
   
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

Size Detector::resize(Mat frame) { return frame.size(); }
