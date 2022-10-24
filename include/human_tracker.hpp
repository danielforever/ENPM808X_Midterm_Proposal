/**
 * @file human_tracker.hpp
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
  void SetVideoDirectory(const std::string& Videodirectory);
  // Getter
  std::string GetVideoDirectory();
  /**
   *  @Brief Destructor
   *
   */
  ~Human_Tracker();
};