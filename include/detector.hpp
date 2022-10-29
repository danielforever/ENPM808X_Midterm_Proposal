#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_
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

#include <chrono>
#include <fstream>
#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>
#include <string>
#include <vector>


/**
 * @Brief  A class that detect and add Person object for the vector
 */
class Detector {
 public:
  bool isInitialized = false;
  /**
   *
   *  @Param confThreshold threshold for confidence
   *  @Param nmsThreshold Non-maximum suppression threshold
   *  @Param inputWidth Width of the input image
   *  @Param inputHeight Height of the input image
   *  @Param modelConfiguration yolov3.cfg directory
   *  @Param modelWeights yolov3.weights directory
   *  @Param cocoFile coco.names directory
   *  @Param outputFile The output of the file name
   *  @Param inputStype separate video or image input type
   *  @Param classes store the coco.names classes
   *  @Param objectTrackingid Store the person id from tracking system into a vector
   *  @Param confidences store the confidences result into vector
   *  @Param boxes store the bounding box result into vector
   *  @Param frameResult store the result frame
   *  @Param names store the model names
   *  @Param roboticRefFrame Store the x, y and z factor
   *  @Param cap store the video capture object
   *  @Param outputFrame store the video capture object
   *  @Param frame store the video capture object
   *  @Param widthRatio store the video capture object
   *  @Param heightRatio store the video capture object
   *  @Param net store the video capture object
   *  @Param newSize store the video capture object
   * 
   * 
   */
  float confThreshold = 0.6;
  float nmsThreshold = 0.3;  // Non-maximum suppression threshold
  int inputWidth = 416;      // Width of network's input image
  int inputHeight = 416;     // Height of network's input image
  std::string modelConfiguration = "../cfg/yolov3.cfg";
  std::string modelWeights = "../cfg/yolov3.weights";
  std::string cocoFile = "../cfg/coco.names";
  std::string outputFile;
  std::string inputStype;
  std::vector<std::string> classes;
  std::vector<int> objectTrackingid;
  std::vector<float> confidences;
  std::vector<cv::Rect> boxes;
  std::vector<cv::Rect> trackerBoxes;
  std::vector<cv::Mat> frameResult;
  std::vector<std::string> names;
  std::vector<int> classIds;
  std::vector<std::array<double, 3>> roboticRefFrame;
  cv::VideoCapture cap;
  cv::Mat outputFrame;
  cv::Mat frame;
  int widthRatio;
  int heightRatio;
  cv::dnn:Net net;
  cv::Size newSize;
  cv::VideoWriter video;
  std::vector<int> index;

  /**
   *  @Brief Constructor
   *
   *  @Param PersonVectorDetector Save all the detected people into vector
   *
   */
  Detector(cv::VideoCapture Cap, const std::string& InputType);
  /**
   *  @Brief Send to object regonition system
   *
   */
  bool DetectorSystem(const cv::Mat& frame);
  /**
   *  @Brief Draw bounding box for the image and filter the low confident
   *
   */
  int DrawBoundingBox();

  cv::Size boxSize();

  void drawPred(int left, int right, int top, int bottom, int idname, double x, double y, double z);

  void getOutputsNames();
  /**
   *  @Brief Distructor for the Dectector class
   *
   */
  void CleanAndDisplay();
  ~Detector();

};
#endif  // INCLUDE_DETECTOR_HPP_
