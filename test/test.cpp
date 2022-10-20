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


TEST(Path, ImagePathCheck) {
  image1.setInput(image_path);
  std::string path_test = image1.getInput();
  EXPECT_EQ(path_test,image_path);
}

TEST(Path, VideoPathCheck) {
  video1.setInput(video_path);
  std::string path_test = video1.getInput();
  EXPECT_EQ(path_test,video_path);
}
