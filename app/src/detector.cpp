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

    }

void Detector::getOutputsNames() {

}

Size Detector::boxSize() { 


    }

void Detector::drawPred(int classId, float conf, int left, int top, int right, int bottom) {

 }


/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const Mat& Frame) { 
    this->frame = Frame;

}

Detector::~Detector() { isInitialized = false; }

/**
 * @brief
 *
 * @return true
 * @return false
 */

int Detector::DrawBoundingBox() {

}


void Detector::CleanAndDisplay(){
    this->confidences.clear();
    this->boxes.clear();
}