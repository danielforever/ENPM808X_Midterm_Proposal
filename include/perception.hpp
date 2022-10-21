/**
 * @file perception.h
 * @Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>




/**
 * @Brief  A class that starts the whole system
 */

class Human_Tracker {
  /**
   *  @Brief Create a Human Tracker class
   *
   */
public:
  bool isInitialized = false;
  std::string videodirectory = "";
  /**
   *  @Brief Constructor
   *
   */
  Human_Tracker();
  // Setter
  void SetVideoDirectory(std::string Videodirectory);
  // Getter
  std::string GetVideoDirectory();
  /**
   *  @Brief Destructor
   *
   */
  ~Human_Tracker();
};

/**
 * @Brief  A class that read images or videos from the directory
 */
class Camera {

private:
  /**
   *
   *  @Param VideoObject This store the object of the video
   *  @Param ImageWeight Store image weight
   *  @Param ImageHeight Store image height
   *
   */
  // cv::VideoCapture VideoObject;
  float ImageWeight;
  float ImageHeight;

public:
  /**
   *
   *  @Param VideoDirectory Read video directory from system
   *
   */
  int LoadVideo(std::string Videodirectory);
  int LoadImage(std::string path);
  Camera();
  ~Camera();
};

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
  Detector();
  Detector(std::string path);
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


class Tracker
{

 public:
    bool isInitialized = false;
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    Tracker();
    ~Tracker();
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    int Tracking();
    /**
     *  @Brief Calculate the distance for the detected object
     *
     */
    int DistanceCalculation();
    /**
     *  @Brief Delete the Object Person that existed in the perivous image
     *
     */
    int DeletePerson();

};

