/**
 * @file camera.hpp
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