#ifndef INCLUDE_CAMERA_HPP_
#define INCLUDE_CAMERA_HPP_
/**
 * @file camera.hpp
 * @author Shantanu Aman Po-Yu
 * @brief Camera Class to initialize and set the camera settings
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
 * @brief A class that read images or videos from the directory
 * 
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
  /**
   * @brief Reading the video or image from the directory
   * 
   * @param Videodirectory 
   * @param VideoOrImage 
   * @return cv::VideoCapture 
   */
  cv::VideoCapture LoadVideo(std::string Videodirectory,
                             const std::string& VideoOrImage);
  Camera();
  ~Camera();
};
#endif  // INCLUDE_CAMERA_HPP_
