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
  Human_Tracker a;
  Detector d;
  Tracker t;
  return 0;
}
