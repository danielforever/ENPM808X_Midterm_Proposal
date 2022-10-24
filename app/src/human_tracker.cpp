/**
 * @file human_tracker.cpp
 * @author Shantanu Aman Po-Yu
 * @brief
 * @version 0.1
 * @date 2022-10-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../../include/human_tracker.hpp"

#include <camera.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

/**
 * @brief set the video directory that will be required for the loading video
 *
 * @param Videodirectory for the video directory
 */
void Human_Tracker::SetVideoDirectory(const std::string& Videodirectory) {
  this->videodirectory = Videodirectory;
}
/**
 * @brief getting the path of the video directory
 *
 * @return std::string returning the video directory
 */
std::string Human_Tracker::GetVideoDirectory() { return videodirectory; }
/**
 * @brief Construct a new Human_Tracker::Human_Tracker object
 *
 */
Human_Tracker::Human_Tracker() {
  isInitialized = true;
  Camera camera;
  std::string path = "../assets/images/pedestrian_single.jpg";
  camera.LoadImage(path);
}
/**
 * @brief Destroy the Human_Tracker::Human_Tracker object
 *
 */
Human_Tracker::~Human_Tracker() { isInitialized = false; }
