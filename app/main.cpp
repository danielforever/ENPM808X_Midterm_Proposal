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
  Human_Tracker a;
  a.SetVideoDirectory("../assets/videos/double_person.mp4");
  Camera h;
  h.LoadImage(a.GetVideoDirectory());
  cv::VideoCapture cap = h.LoadVideo(a.GetVideoDirectory(), "video");
  Detector d(cap, h.videoorimage);
  Mat frame;
  Tracker t;
  while (waitKey(1) < 0){
    d.cap >> frame;
    if (frame.empty()) {
      waitKey(3000);
      break;
    }
    d.DetectorSystem(frame);
    t.Tracking(d.preOuts,d.curOuts);
    
    t.DeletePerson();
    t.DistanceCalculation();
    d.DrawBoundingBox();

  }

  return 0;
}
