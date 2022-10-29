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

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc/imgproc.hpp>


/**
 * @Brief  A class that detect and add Person object for the vector
 */
class Detector {
 public:
  bool isInitialized = false;
  /**
   *
   *  @param confThreshold threshold for confidence
   *  @param nmsThreshold Non-maximum suppression threshold
   *  @param inputWidth Width of the input image
   *  @param inputHeight Height of the input image
   *  @param modelConfiguration yolov3.cfg directory
   *  @param modelWeights yolov3.weights directory
   *  @param cocoFile coco.names directory
   *  @param outputFile The output of the file name
   *  @param inputStype separate video or image input type
   *  @param classes store the coco.names classes
   *  @param objectTrackingid Store the person id from tracking system into a
   * vector
   *  @param confidences store the confidences result into vector
   *  @param boxes store the bounding box result into vector
   *  @param frameResult store the result frame
   *  @param names store the model names
   *  @param roboticRefFrame Store the x, y and z factor
   *  @param cap store the video capture object
   *  @param outputFrame store the video capture object
   *  @param frame store the video capture object
   *  @param widthRatio store the video capture object
   *  @param heightRatio store the video capture object
   *  @param net store the video capture object
   *  @param newSize store the video capture object
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
  cv::dnn::Net net;
  cv::Size newSize;
  cv::VideoWriter video;
  std::vector<int> index;


/**
 * @brief Construct a new Detector object
 * 
 * @param Cap 
 * @param InputType 
 */
  Detector(cv::VideoCapture Cap, const std::string& InputType);


/**
 * @brief Initialize the frame and send it to the YOLO model and
 * store the bounding box of the detected object.
 * 
 * @param Frame 
 * @return true 
 * @return false 
 */
  bool DetectorSystem(const cv::Mat& frame);
  /**
   *  @brief Draw bounding box for the image and filter the low confident
   *
   */
  int DrawBoundingBox();

  cv::Size boxSize();
  /**
 * @brief Drawing the bounding box and lable on the frame.
 * 
 * @param left 
 * @param right 
 * @param top 
 * @param bottom 
 * @param idname 
 * @param x 
 * @param y 
 * @param z 
 */
  void drawPred(int left, int right, int top, int bottom, int idname, double x,
                double y, double z);

  /**
   * @brief Reading the names of classes from coco.names
   * 
   */
  void getOutputsNames();

  /**
 * @brief Return the imageafter drawing and cleaning the bounding boxes
 * 
 * @return cv::Mat 
 */
  cv::Mat CleanAndDisplay();

  /**
   * @brief Destroy the Detector object
   * 
   */
  ~Detector();
};
#endif  // INCLUDE_DETECTOR_HPP_

