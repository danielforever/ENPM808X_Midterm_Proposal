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
/**
 * @brief
 *
 * @param path giving the path
 * @return int
 */
int Camera::LoadImage(std::string path) {
  std::string image_path = cv::samples::findFile(path);
  cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
  if (img.empty()) {
    std::cout << "Could not read the image: " << image_path << std::endl;
    return 1;
  }
  imshow("Display window", img);
  int k = cv::waitKey(0);  // Wait for a keystroke in the window
  if (k == 's') {
    imwrite("starry_night.png", img);
  }
  return 0;
}
