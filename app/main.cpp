/**
 * @file main.cpp
 * @author Shantanu Aman Po-Yu 
 * @brief 
 * @version 0.1
 * @date 2022-10-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

#include <camera.hpp>
#include <tracker.hpp>
#include <human_tracker.hpp>
#include <detector.hpp>



int main() {
  Camera h;
  std::string path = "../assets/images/pedestrian_single.jpg";
  h.LoadImage(path);
  std::string video_path = "../assets/videos/double_person.mp4";
  cv::VideoCapture cap = h.LoadVideo(video_path, "video");
  // cv::VideoCapture cap1 = h.LoadVideo(path, "image");
  Human_Tracker a;
  cout << "check: " << endl;

  Detector d(cap, h.videoorimage);
  cout << "check" << endl;
  return 0;
}
