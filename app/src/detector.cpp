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
    int width = this->frame.cols;
    int height = this->frame.rows;
    float ratio = float(416)/max(width, height);
    this->widthRatio = int(round(width * ratio));
    this->heightRatio = int(round(height * ratio));
    int newWidth = ((416 - this->widthRatio) % 32 )/2;
    int newHeight = ((416 - this->heightRatio) % 32 )/2;
    int left = int(round(newWidth - 0.1));
    int right = int(round(newWidth + 0.1));
    int top = int(round(newHeight - 0.1));
    int bottom = int(round(newHeight + 0.1));
    cout<<"widthRatio: "<<this->widthRatio<<endl;
    cout<<"heightRatio: "<<this->heightRatio<<endl;

    cv::resize(this->frame, this->frame, cv::Size(this->widthRatio, this->heightRatio), 0, 0, 1); 
    Scalar value(127.5, 127.5, 127.5);
    cv::copyMakeBorder(this->frame, this->frame, top, bottom, left, right, cv::BORDER_CONSTANT, value);
    return this->frame.size();
    }

void Detector::drawPred(int classId, float conf, int left, int top, int right, int bottom) {

 }


/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const Mat& Frame) { 
    this->frame = Frame;
    cout<<"Detect system on"<<endl;
    
    cv::cvtColor(this->frame, this->frame, COLOR_BGR2RGB);
    cout << "Before Resize:" << this->frame.cols << " " << this->frame.rows << endl;
    this->newSize = this->boxSize();
    cout << "After Resize:" << this->newSize.width << " " << this->newSize.height << endl;
    
    Mat blob;
    blobFromImage(this->frame, blob, 1/255.0, Size(this->inputWidth, this->newSize.height), Scalar(0,0,0), true, false); 
    this->net.setInput(blob);
        
    
    if (this->names.empty()){
        
        vector<int> outLayers = this->net.getUnconnectedOutLayers();
        
        vector<String> layersNames = this->net.getLayerNames();
       
        this->names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i)
            this->names[i] = layersNames[outLayers[i] - 1];
    }
    this->net.forward(this->frameResult, this->names);
    cout<<"Detect system off"<<endl;
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