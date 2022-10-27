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

using namespace cv;
using namespace cv::dnn;
using namespace std;
using namespace std::chrono;
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
   *  @Param classes store the coco.names classes
   *  @Param objectClasses Store the object class into a vector
   *  @Param outputFile string that store output directory
   *  @Param objectConfidences Store the object confidence into a vector
   *  @Param cap store the video capture object
   *  @Param inputStype store the video capture object
   *  @Param cap store the video capture object
   *
   */
  float confThreshold = 0.6;
  float nmsThreshold = 0.6;  // Non-maximum suppression threshold
  int inputWidth = 416;      // Width of network's input image
  int inputHeight = 416;     // Height of network's input image
  String modelConfiguration = "../cfg/yolov3.cfg";
  String modelWeights = "../cfg/yolov3.weights";
  vector<string> classes;
  vector<string> objectClasses;
  string outputFile;
  vector<float> confidences;
  vector<Rect> boxes;
  VideoCapture cap;
  string inputStype;
  vector<Mat> preOuts;
  vector<Mat> curOuts;
  vector<string> names;
  VideoWriter video;
  vector<Mat> frameResult;
  Mat outputFrame;
  Mat frame;
  string fileName = "../cfg/coco.names";
  string str;
  int DrawBoundingBoxcheck = 0;
  int resizecheck = 0;
  int drawPredcheck = 0;
  int left, top, right, bottom;
  int widthRatio;
  int heightRatio;
  Net net;
  Size newSize;
  string label;

  /**
   *  @Brief Constructor
   *
   *  @Param PersonVectorDetector Save all the detected people into vector
   *
   */
  Detector(VideoCapture Cap, const string& InputType);
  /**
   *  @Brief Send to object regonition system
   *
   */
  bool DetectorSystem(const Mat& frame);
  /**
   *  @Brief Draw bounding box for the image and filter the low confident
   *
   */
  int DrawBoundingBox();

  Size boxSize();

  void drawPred(int classId, float conf, int left, int top, int right, int bottom);

  void getOutputsNames();
  /**
   *  @Brief Distructor for the Dectector class
   *
   */
  void CleanAndDisplay();
  ~Detector();

};