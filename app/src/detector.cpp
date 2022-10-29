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
    this->inputStype = Inputstype;
    this->net = readNetFromDarknet(modelConfiguration, modelWeights);
    this->net.setPreferableBackend(DNN_BACKEND_OPENCV);
    this->net.setPreferableTarget(DNN_TARGET_CPU);
    
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
            cout << "image check!" << endl;
            this->video.open(this->outputFile, VideoWriter::fourcc('M', 'J', 'P', 'G'), 28, Size(this->cap.get(CAP_PROP_FRAME_WIDTH), this->cap.get(CAP_PROP_FRAME_HEIGHT)), true);
            cout << "image check!" << endl;
        }
    }

void Detector::getOutputsNames() {
    ifstream in(this->cocoFile.c_str());
    string str;
    while (getline(in, str))
    {
        
        if(str.size() > 0) this->classes.push_back(str);
    }
    cout << "load coco.names" << endl;

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
    // cout << "widthRatio: " << this->widthRatio<<endl;
    // cout << "heightRatio: " << this->heightRatio<<endl;

    cv::resize(this->frame, this->frame, cv::Size(this->widthRatio, this->heightRatio), 0, 0, 1); 
    Scalar value(127.5, 127.5, 127.5);
    cv::copyMakeBorder(this->frame, this->frame, top, bottom, left, right, cv::BORDER_CONSTANT, value);
    return this->frame.size();
    }

void Detector::drawPred(int left, int right, int top, int bottom, int idname) {
    rectangle(this->frame, Point(left, top), Point(right, bottom), Scalar(255, 178, 50), 3);
    cout<<"bounding box check2"<<endl;
    string label = "Person" + to_string(idname);
    
    int baseLine;
    Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = max(top, labelSize.height);
    rectangle(this->frame, Point(left, top - round(1.5*labelSize.height)), Point(left + round(1.5*labelSize.width), top + baseLine), Scalar(255, 255, 255), FILLED);
    putText(this->frame, label, Point(left, top), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0,0,0),1);
    }


/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const Mat& Frame) { 
    this->frame = Frame;
    Mat blob;
    cout<<"Detect system on"<<endl;
    
    cv::cvtColor(this->frame, this->frame, COLOR_BGR2RGB);
    //cout << "Before Resize:" << this->frame.cols << " " << this->frame.rows << endl;
    this->newSize = this->boxSize();
    //cout << "After Resize:" << this->newSize.width << " " << this->newSize.height << endl;
    

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
    for (size_t i = 0; i < this->frameResult.size(); ++i)
    {
        float* result = (float*)this->frameResult[i].data;
        for (int j = 0; j < this->frameResult[i].rows; ++j, result += this->frameResult[i].cols)
        {
            Mat scores = this->frameResult[i].row(j).colRange(5, this->frameResult[i].cols);
            Point classIdPoint;
            double confidence;
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > this->confThreshold and classIdPoint.x==0)
            {
                int centerX = (int)(result[0] * frame.cols);
                int centerY = (int)(result[1] * frame.rows);
                int width = (int)(result[2] * frame.cols);
                int height = (int)(result[3] * frame.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;
                int right = centerX + width / 2;
                int bottom = centerY + height / 2;                
                this->classIds.push_back(classIdPoint.x);
                cout << "centerX: " << centerX << endl;
                cout << "centerY: " << centerY << endl;
                // cout << "width: " << width << endl;
                //cout << "height: " << height << endl;  
                // cout << "left: " << left << endl;
                // cout << "right: " << right << endl;
                // cout << "top: " << top << endl;   
                // cout << "bottom: " << bottom << endl;                                  
                this->confidences.push_back((float)confidence); 
                this->boxes.push_back(Rect(left, top, width, height));
            }
        }
    }
    NMSBoxes(this->boxes, this->confidences, this->confThreshold, this->nmsThreshold, this->index);
    for (auto i: this->index)
        this->trackerBoxes.push_back(this->boxes[i]);
    
    return true;
    }

Detector::~Detector() { isInitialized = false; }


int Detector::DrawBoundingBox() {
    cout << this->boxes.size() << endl;

    
    for (size_t i = 0; i < this->index.size(); ++i)
    {
        cout<<"check times"<<endl;
        int idx = this->index[i];
        Rect box = this->boxes[idx];
        drawPred(box.x, box.x + box.width, box.y, box.y + box.height, this->objectTrackingid[i]);
   }

    return 0;
}


void Detector::CleanAndDisplay(){
    Mat detectedFrame;
    this->frame.convertTo(detectedFrame, CV_8U);
    cv::cvtColor(detectedFrame,detectedFrame, COLOR_RGB2BGR);
    if (this->inputStype == "image") imwrite(this->outputFile, detectedFrame);
    else this->video.write(detectedFrame);
        
    imshow("Display", detectedFrame);
    this->confidences.clear();
    this->boxes.clear();
    this->classIds.clear();
    this->trackerBoxes.clear();
    this->objectTrackingid.clear();
}