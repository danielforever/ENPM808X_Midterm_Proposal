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

#include <iostream>
#include <vector>
#include <string>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
/**
 * @Brief  A class that detect and add Person object for the vector
 */
class Detector {
 public:
     bool isInitialized = false;
  /**
   *
   *  @Param boxes Store the bounding box coordinate into a vector
   *  @Param Confidences Store the confidences into a vector
   *
   */
  std::vector<cv::Rect> boxes;
  std::vector<float> Confidences;
  Detector(cv::VideoCapture cap);
  explicit Detector(std::string path);
  ~Detector();
  /**
   *  @Brief Constructor
   *
   *  @Param PersonVectorDetector Save all the detected people into vector
   *
   */

  /**
   *  @Brief Send to object regonition system
   *
   */
  bool DetectorSystem();
  /**
   *  @Brief To transform the cooridnate to Robot frame and calculate the center
   * point
   *
   */
  int CoordinateTransform();
  /**
   *  @Brief Draw bounding box for the image
   *
   */
  int DrawBoundingBox();
};