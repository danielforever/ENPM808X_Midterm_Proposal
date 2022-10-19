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
#include "perception.h"

std::string image_path = "asset/images/pedestrian_single.jpg";
std::string video_path = "asset/videos/double_person.mp4";
Human_Tracker image1(image_path);
Human_Tracker video1(video_path);


TEST(Path, ImagePathCheck) {
  path_test= image1.MediaPath;
  EXPECT_EQ(path_test,image_path);
}

TEST(Path, VideoPathCheck) {
  path_test= video1.MediaPath;
  EXPECT_EQ(path_test,video_path);
}


