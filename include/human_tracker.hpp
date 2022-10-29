#ifndef INCLUDE_HUMAN_TRACKER_HPP_
#define INCLUDE_HUMAN_TRACKER_HPP_
/**
 * @file human_tracker.hpp
 * @author Shantanu Aman Po-Yu
 * @brief Template for the Human_Tracker Class
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
 * @brief A  class that starts the whole system
 * 
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
   * @brief Construct a new Human_Tracker object
   * 
   */
  Human_Tracker();
  /**
   * @brief Set the Video Directory object
   * 
   * @param Videodirectory 
   */
  void SetVideoDirectory(const std::string& Videodirectory);
  /**
   * @brief Get the Video Directory object
   * 
   * @return std::string 
   */
  std::string GetVideoDirectory();
  /**
   * @brief Destroy the Human_Tracker object
   * 
   */
  ~Human_Tracker();
};
#endif  // INCLUDE_HUMAN_TRACKER_HPP_
