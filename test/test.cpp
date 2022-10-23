/**
 * @file test.cpp
 * @Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>
#include <camera.hpp>
#include <tracker.hpp>
#include <human_tracker.hpp>
#include <detector.hpp>





Human_Tracker image1;
Human_Tracker video1;
/**
 * @brief Test for the Human Tracker Constructor and Destructor
 *
 */

TEST(HumanTrackerTest, HumanTrackerConstructor) {
  EXPECT_EQ(image1.isInitialized, true);
}
/**
 * @brief Construct a new TEST object for Human Tracker
 * 
 */
TEST(HumanTrackerTest, HumanTrackerDestructor) {
  image1.~Human_Tracker();
  EXPECT_EQ(image1.isInitialized, false);
}
/**
 * @brief Test for the Camera Class
 * 
 */
Camera Camera1;
Camera Camera2;
/**
 * @brief Testing for the Human Tracker Function against an image
 * 
 */
TEST(Path, ImagePathCheck) {
  std::string image_path = "assets/images/pedestrian_single.jpg";
  image1.SetVideoDirectory(image_path);
  std::string path_test = image1.GetVideoDirectory();
  EXPECT_EQ(path_test, image_path);
}
/**
 * @brief Testing the Human Tracker against a video 
 * 
 */
TEST(Path, VideoPathCheck) {
  std::string video_path = "assets/videos/double_person.mp4";
  video1.SetVideoDirectory(video_path);
  std::string path_test = video1.GetVideoDirectory();
  EXPECT_EQ(path_test, video_path);
}
/**
 * @brief Testing the Video Loading 
 * 
 */
cv::VideoCapture cap2 = Camera2.LoadVideo(video1.GetVideoDirectory());

TEST(Number, VideoObjectCheck) {
  
  int value = 1;
  if(!cap2.isOpened()){
    value = 0;
  }
  EXPECT_EQ(value, 1);
}
/**
 * @brief Testing the Detector Constructor
 * 
 */
TEST(Detector, DetectorConstructor) {
  Detector trackerObject(cap2);
  EXPECT_EQ(trackerObject.isInitialized, true);
}
/**
 * @brief Testing the Detector Destructor 
 * 
 */
TEST(Detector, DetectorDestructor) {
  Detector trackerObject(cap2);
  trackerObject.~Detector();
  EXPECT_EQ(trackerObject.isInitialized, false);
}
/**
 * @brief Testing the Detection Counting Function for the single image
 * 
 */
TEST(Detector, DetectObjectCheck0) {
  Detector system1("../assests/pedestrian_single.jpg");
  EXPECT_EQ(system1.DetectorSystem(), 1);
  }
/**
 * @brief Testing the Detector counting function for double pedestrian image
 * 
 */
Detector system1("../assests/pedestrian-walk-car-waiting.jpg");
TEST(Detector, DetectObjectCheck1) {
  EXPECT_EQ(system1.DetectorSystem(), 2);
}

/**
 * @brief Coordinate system transformation tests 
 * 
 */
TEST(Coordinate, CoordinateCheck) {
  EXPECT_EQ(system1.CoordinateTransform(), 1);
}
/**
 * @brief Bouding box testing 
 * 
 */
TEST(Number, BoundingBoxCheck) { EXPECT_EQ(system1.DrawBoundingBox(), 2); }
/**
 * @brief Testing the Tracker
 * 
 */
Tracker system1_tracker;


TEST(Number, TrackingObjectCheck) { EXPECT_EQ(system1_tracker.Tracking(), 2); }

/**
 * @brief Construct a new TEST object
 * To check if the constructor is being called
 */
TEST(TrackerTest, TrackerConstructor) {
  Tracker trackerObject;
  EXPECT_EQ(trackerObject.isInitialized, true);
}
/**
 * @brief Test case for tracker destructor
 * 
 */
TEST(TrackerTest, TrackerDestructor) {
  Tracker trackerObject;
  trackerObject.~Tracker();
  EXPECT_EQ(trackerObject.isInitialized, false);
}
/**
 * @brief Test case for Distance Calculation
 * 
 */
TEST(Number, DistanceCalculationCheck) {
  EXPECT_EQ(system1_tracker.DistanceCalculation(), 0);
}
/**
 * @brief Testing case for Deleted Person
 * 
 */
TEST(Number, DeletePersonCheck) {
  EXPECT_EQ(system1_tracker.DeletePerson(), 3);
}
