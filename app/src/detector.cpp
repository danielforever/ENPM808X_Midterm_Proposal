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


using namespace cv;
using namespace dnn;
using namespace std;
/**
 * @brief Construct a new Detector:: Detector object
 *
 */
Detector::Detector(VideoCapture Cap, const string& Inputstype) {
    this->cap = Cap;
    this-> inputStype = Inputstype;
    this->net = readNetFromDarknet(modelConfiguration, modelWeights);
    this->net.setPreferableBackend(DNN_BACKEND_OPENCV);
    this->net.setPreferableTarget(DNN_TARGET_CPU);
    VideoWriter video;
    try {
        if (this->inputStype == "image")
        {
            cout<<"suceess read image."<<endl;
            this->outputFile = "result.jpg";
        }
        else if (this->inputStype == "video")
        {
            cout<<"suceess read video."<<endl;
            this->outputFile = "result.avi";
        }
        }
        catch(...) {
            cout << "Error: Did not detect any valid input file." << endl;
        }
        if (this->inputStype != "image") {
            cout<<"image check!"<<endl;
            video.open(this->outputFile, VideoWriter::fourcc('M', 'J', 'P', 'G'), 28, Size(this->cap.get(CAP_PROP_FRAME_WIDTH), this->cap.get(CAP_PROP_FRAME_HEIGHT)), true);
            cout<<"image check!"<<endl;
        }
    }

void Detector::getOutputsNames() {
    ifstream in(this->cocoFile.c_str());
    string str;
    while (getline(in, str))
    {
        
        if(str.size() > 0) this->classes.push_back(str);
    }
    cout<<"load coco.names"<<endl;

}

Size Detector::boxSize() { 

    return frame.size();
    }

void Detector::drawPred(int classId, float conf, int left, int top, int right, int bottom) {

 }


/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const Mat& Frame) { 
    this->frame = Frame;
    
    return true;
}

Detector::~Detector() { isInitialized = false; }

/**
 * @brief
 *
 * @return true
 * @return false
 */

int Detector::DrawBoundingBox() {

    return 0;
}


void Detector::CleanAndDisplay(){

}