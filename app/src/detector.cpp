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
void Detector::createClass() {}

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
bool Detector::DetectorSystem() { return 0; }
Detector::~Detector() { isInitialized = false; }

/**
 * @brief
 *
 * @return true
 * @return false
 */

int Detector::CoordinateTransform() { return 0; }

void Detector::DrawBoundingBox(Mat& frame, Mat& oldframe,
                               const vector<Mat>& outs) {}

Size Detector::letterbox(Mat frame) { return frame.size(); }
