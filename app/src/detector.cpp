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

}
void Detector::drawPred() {
}

void Detector::getOutputsNames() {

}
/**
 * @brief Destroy the Detector:: Detector object
 *
 */
bool Detector::DetectorSystem(const Mat& frame) { 
    return 0; }

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

int Detector::resize() { 
    return 0;
    }
