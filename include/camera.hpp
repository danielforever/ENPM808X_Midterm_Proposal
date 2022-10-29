#ifndef INCLUDE_CAMERA_HPP_
#define INCLUDE_CAMERA_HPP_
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
#include <string>
#include <vector>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>


/**
 * @Brief  A class that read images or videos from the directory
 */
class Camera {
 private:
  /**
   *
   *  @Param VideoObject This store the object of the video
   *
   */

 public:
  /**
   *
   *  @Param VideoDirectory Read video directory from system
   *  @Param cap Load video into the VideoCapture
   *
   */
  std::string videoorimage;
  cv::VideoCapture cap;
  cv::VideoCapture LoadVideo(std::string Videodirectory,
                             const std::string& VideoOrImage);
  Camera();
  ~Camera();
};
#endif  // INCLUDE_CAMERA_HPP_
