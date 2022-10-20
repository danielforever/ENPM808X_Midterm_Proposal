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
#include "../include/perception.hpp"

std::string image_path = "asset/images/pedestrian_single.jpg";
std::string video_path = "asset/videos/double_person.mp4";

Human_Tracker image1;
Human_Tracker video1;

Camera Camera1;
Camera Camera2;

TEST(Path, ImagePathCheck) {
  image1.SetVideoDirectory(image_path);
  std::string path_test = image1.GetVideoDirectory();
  EXPECT_EQ(path_test,image_path);
}

TEST(Path, VideoPathCheck) {
  video1.SetVideoDirectory(video_path);
  std::string path_test = video1.GetVideoDirectory();
  EXPECT_EQ(path_test,video_path);
}

TEST(Number, ImageObjectCheck) {
  int value = Camera1.LoadVideo(image1.GetVideoDirectory());
  EXPECT_EQ(value,1);
}

TEST(Number, VideoObjectCheck) {
  int value = Camera2.LoadVideo(video1.GetVideoDirectory());
  EXPECT_EQ(value,1);
}

TEST(Detector, DetectorConstructor) {
  Detector trackerObject;
  EXPECT_EQ(trackerObject.isInitialized, true);
}
TEST(Detector, DetectorDestructor) {
  Detector trackerObject;
  trackerObject.~Detector();
  EXPECT_EQ(trackerObject.isInitialized, false);
}

Detector system1;

TEST(Object, DetectObjectCheck) {
  EXPECT_EQ(system1.DetectorSystem(),true);
}

TEST(Coordinate, CoordinateCheck) {
  EXPECT_EQ(system1.CoordinateTransform(),1);
}


TEST(Number, BoundingBoxCheck) {
  EXPECT_EQ(system1.DrawBoundingBox(),2);
}

Tracker system1_tracker;

/**
 * @brief Construct a new TEST object
 * To check if the constructor is being called
 */
TEST(TrackerTest, TrackerConstructor) {
  Tracker trackerObject;
  EXPECT_EQ(trackerObject.isInitialized, true);
}
TEST(TrackerTest, TrackerDestructor) {
  Tracker trackerObject;
  trackerObject.~Tracker();
  EXPECT_EQ(trackerObject.isInitialized, false);
}

TEST(Number, TrackingObjectCheck) {
  EXPECT_EQ(system1_tracker.Tracking(),2);
}

TEST(Number, DistanceCalculationCheck) {
  EXPECT_EQ(system1_tracker.DistanceCalculation(),0);
}

TEST(Number, DeletePersonCheck) {
  EXPECT_EQ(system1_tracker.DeletePerson(),3);
}