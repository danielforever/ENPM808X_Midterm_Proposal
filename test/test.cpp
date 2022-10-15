/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <gtest/gtest.h>
#include <./perception.h>

Camera video1;

TEST(LoadVideo, case1) {
  EXPECT_EQ(video1.LoadVideo(./video/sample1), 1);
}

TEST(LoadVideo, case2) {
  EXPECT_EQ(video1.LoadVideo(), -1);
}
