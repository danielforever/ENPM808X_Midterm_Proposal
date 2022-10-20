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

TEST(Object, ImageObjectCheck) {
  int value = Camera1.LoadVideo(image1.GetVideoDirectory());
  EXPECT_EQ(value,1);
}

TEST(Object, VideoObjectCheck) {
  int value = Camera2.LoadVideo(video1.GetVideoDirectory());
  EXPECT_EQ(value,1);
}

TEST(Object, DetectObjectCheck) {
  EXPECT_EQ(DetectorSystem(),true);
}

TEST(Coordinate, CoordinateCheck) {
  EXPECT_EQ(CoordinateTransform(),1);
}


