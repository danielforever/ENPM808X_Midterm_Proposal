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
  Human_Tracker b;
  Human_Tracker c;
  Human_Tracker e;
  a.SetVideoDirectory("../assets/videos/single_person.mp4");
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  c.SetVideoDirectory("../assets/videos/double_simple.mp4");
  e.SetVideoDirectory("../assets/videos/double_person.mp4");
  Camera h;
  // h.LoadImage(a.GetVideoDirectory());
  // Detector d(h.LoadVideo(a.GetVideoDirectory(), "video"), h.videoorimage);
  // Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Detector d(h.LoadVideo(c.GetVideoDirectory(), "video"), h.videoorimage);
  // Detector d(h.LoadVideo(e.GetVideoDirectory(), "video"), h.videoorimage);
  Tracker t;
  cv::Mat frame;
  d.getOutputsNames();
  while (cv::waitKey(1) < 0) {
    d.cap >> frame;
    if (frame.empty()) {
      cv::waitKey(3000);
      break;
    }
    d.DetectorSystem(frame);
    d.objectTrackingid = t.Tracking(d.trackerBoxes);
    d.roboticRefFrame = t.roboticRefFrame;
    d.DrawBoundingBox();
    imshow("Display", d.CleanAndDisplay());
  }

  return 0;
}
