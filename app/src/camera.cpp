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
#include "../../include/camera.hpp"

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

/**
 * @brief Construct a new Camera:: Camera object
 *
 */
Camera::Camera() {}
Camera::~Camera() {}
/**
 * @brief
 *
 * @param Videodirectory Loadin the Video Directory
 * @return cv::VideoCapture
 */
cv::VideoCapture Camera::LoadVideo(std::string Videodirectory,
                                   const std::string& VideoOrImage) {
  cv::VideoCapture cap(Videodirectory);
  this->videoorimage = VideoOrImage;
  return cap;
}

