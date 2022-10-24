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
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <string>
#include <vector>

using namespace cv;
using namespace std;
using namespace std::chrono;

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
  // cv::VideoCapture VideoObject;

 public:
  /**
   *
   *  @Param VideoDirectory Read video directory from system
   *
   */
  string videoorimage;
  cv::VideoCapture LoadVideo(string Videodirectory, const string& VideoOrImage);
  int LoadImage(string path);
  Camera();
  ~Camera();
};