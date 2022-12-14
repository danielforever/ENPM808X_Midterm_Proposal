/**
 * @file test.cpp
 * @Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 * @brief Test Suite 
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


/**
 * @brief A function for integrating the test for 
 * verfiying test output within  a range.
 * 
 * @param val 
 * @param a 
 * @param b 
 * @return ::testing::AssertionResult 
 */
::testing::AssertionResult IsBetweenInclusive(int val, int a, int b) {
    if ((val >= a) && (val <= b))
        return ::testing::AssertionSuccess();
    else
        return ::testing::AssertionFailure()
               << val << " is outside the range " << a << " to " << b;
}


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

/**
 * @brief Testing for the Human Tracker Function against an image
 * 
 */
TEST(Path, ImagePathCheck) {
  std::string image_path = "../assets/images/pedestrian_single.jpg";
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

Camera Camera3;



TEST(CameraTest, VideoObjectCheck) {
  Human_Tracker video2;
  std::string video_path = "assets/videos/double_person.mp4";
  video2.SetVideoDirectory(video_path);
  Camera Camera2;
  Camera2.LoadVideo(video2.GetVideoDirectory(), "video");
  EXPECT_EQ(Camera2.videoorimage, "video");
}
/**
 * @brief Testing the Detector Constructor with the video route
 * 
 */
TEST(DetectorTest, DetectorConstructorVideoTest) {
  Human_Tracker video2;
  std::string video_path = "assets/videos/double_person.mp4";
  video2.SetVideoDirectory(video_path);
  Camera Camera2;
  cv::VideoCapture cap3 = Camera2.LoadVideo(
                    video2.GetVideoDirectory(), "video");
  Detector trackerObject(cap3, "video");
  EXPECT_EQ(trackerObject.outputFile, "result.avi");
}

/**
 * @brief Testing the Detector Constructor with the image route
 * 
 */

TEST(DetectorTest, DetectorConstructorImageTest) {
  std::string image_path = "assets/images/pedestrian_single.jpg";
  image1.SetVideoDirectory(image_path);
  cv::VideoCapture cap3 = Camera3.LoadVideo(
                    image1.GetVideoDirectory(), "image");
  Detector trackerObject(cap3, "image");
  EXPECT_EQ(trackerObject.outputFile, "result.jpg");
}

/**
 * @brief Testing the Detector Destructor 
 * 
 */
TEST(DetectorTest, DetectorDestructor2) {
  Human_Tracker video2;
  std::string video_path = "assets/videos/double_person.mp4";
  video2.SetVideoDirectory(video_path);
  Camera Camera2;
  cv::VideoCapture cap2 = Camera2.LoadVideo(
                             video2.GetVideoDirectory(), "video");
  Detector trackerObject(cap2, "video");
  // trackerObject.~Detector();
  EXPECT_EQ(trackerObject.isInitialized, false);
}
/**
 * @brief Test the label name is what we expect from coco.names
 * 
 */
TEST(DetectorTest, getOutputsNamesCheckReadFile) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  std::string test;
  if (!d.classes.empty()) {
    test = d.classes[0];
  }
  EXPECT_EQ(test, "person");
}

/**
 * @brief Read the label name size is equal to coco.names
 * 
 */
TEST(DetectorTest, getOutputsNamesCheck) {
  Human_Tracker video2;
  std::string video_path = "assets/videos/double_person.mp4";
  video2.SetVideoDirectory(video_path);
  Camera Camera2;
  cv::VideoCapture cap2 = Camera2.LoadVideo(
                        video2.GetVideoDirectory(), "video");
  Detector detectorObject(cap2, "video");
  detectorObject.getOutputsNames();
  std::string classesFile = "../cfg/coco.names";
  std::ifstream ifs(classesFile.c_str());
  std::string line;
  std::vector<std::string> classtest;
  while (getline(ifs, line)) classtest.push_back(line);
  EXPECT_EQ(detectorObject.classes.size(), classtest.size());
}
/**
 * @brief Testing the layername match to what we expected in DetectorSystem function
 * 
 */
TEST(DetectorTest, DetectObjectCheck0) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  std::string test;
  if (!d.names.empty()) {
    test = d.names[0];
  }
  EXPECT_EQ(test, "yolo_82");
  }

/**
 * @brief Test the portion of width that needed to be resize 
 * 
 */

TEST(DetectorTest, FrameboxSizeWidthCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  EXPECT_EQ(d.widthRatio, 416);
}

/**
 * @brief Test the portion of width that needed to be resize 
 * 
 */

TEST(DetectorTest, DrawBoundingBoxHeightCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  EXPECT_EQ(d.heightRatio, 277);
}
/**
 * @brief Test the coordinate of the ounding box saved in the boxes member 
 * 
 */


TEST(DetectorTest, DrawBoundingBoxWidthCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Tracker t;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.objectTrackingid = t.Tracking(d.trackerBoxes);
  d.roboticRefFrame = t.roboticRefFrame;
  d.DrawBoundingBox();
  int test = 0.0;
  if (!d.boxes.empty()) {
    test = d.boxes[0].width;
  }
  EXPECT_TRUE(IsBetweenInclusive(test, 62, 70));
  // EXPECT_EQ(test, 63);
}
/**
 * @brief Test does the function clean the detected object
 * 
 */
TEST(DetectorTest, ClearBoxCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Tracker t;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.objectTrackingid = t.Tracking(d.trackerBoxes);
  d.roboticRefFrame = t.roboticRefFrame;
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  int value = 1;
  if (d.boxes.empty()) {
    value = 0;
  }
  std::cout << "check:" << d.boxes[0].x << std::endl;
  EXPECT_EQ(value, 0);
}

/**
 * @brief Test the center point for the detected object
 * 
 */
TEST(DetectorTest, CleanAndDisplayCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Tracker t;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.objectTrackingid = t.Tracking(d.trackerBoxes);
  d.roboticRefFrame = t.roboticRefFrame;
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  int value = 1;
  if (d.confidences.empty()) {
    value = 0;
  }
  EXPECT_EQ(value, 0);
}
/**
 * @brief Testing the Tracker
 * 
 */


/**
 * @brief Construct a new TEST object
 * To check if the constructor is being called
 */
TEST(TrackerTest, TrackerConstructor) {
  Tracker tracker1;
  EXPECT_EQ(tracker1.isInitialized, true);
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
TEST(TrackerTest, DistanceCalculationCheck) {
  Tracker tracker1;
  float test = 5;
  EXPECT_EQ(tracker1.DistanceCalculation(5, 2, 9, 5), test);
}
/**
 * @brief Test case1 for Tracking Calculation
 * 
 */
TEST(TrackerTest, TrackingFunctionCase1Check) {
  Tracker tracker1;
  std::vector<cv::Rect> testBox;
  std::vector<int> testReturn;
  testBox.push_back(cv::Rect(200, 200, 100, 100));
  testReturn = tracker1.Tracking(testBox);
  int test = 100;
  if (!testReturn.empty()) {
    test = testReturn[0];
  }
  EXPECT_EQ(test, 0); }
/**
 * @brief Test case2 for Tracking Calculation
 * 
 */
TEST(TrackerTest, TrackingFunctionCase2Check) {
  Tracker tracker1;
  std::vector<cv::Rect> testBox;
  std::vector<int> testReturn;
  testBox.push_back(cv::Rect(200, 200, 100, 100));
  tracker1.preid.push_back(0);
  tracker1.PreCenterPoint.emplace_back(249, 249);
  testReturn = tracker1.Tracking(testBox);
  int test = 100;
  if (!testReturn.empty()) {
    test = testReturn[0];
  }
  EXPECT_EQ(test, 0); }
/**
 * @brief Test case3 for Tracking Calculation
 * 
 */
TEST(TrackerTest, TrackingFunctionCase3Check) {
  Tracker tracker1;
  std::vector<cv::Rect> testBox;
  std::vector<int> testReturn;
  testBox.push_back(cv::Rect(200, 200, 100, 100));
  tracker1.preid.push_back(0);
  tracker1.PreCenterPoint.emplace_back(255, 255);
  tracker1.preid.push_back(1);
  tracker1.PreCenterPoint.emplace_back(249, 249);
  testReturn = tracker1.Tracking(testBox);
  int test = 100;
  if (!testReturn.empty()) {
    test = testReturn[0];
  }
  EXPECT_EQ(test, 1); }
/**
 * @brief Test case4 for Tracking Calculation
 * 
 */
TEST(TrackerTest, TrackingFunctionCase4Check) {
  Tracker tracker1;
  std::vector<cv::Rect> testBox;
  std::vector<int> testReturn;
  testBox.push_back(cv::Rect(200, 200, 100, 100));
  tracker1.preid.push_back(0);
  tracker1.PreCenterPoint.emplace_back(150, 150);
  tracker1.preid.push_back(1);
  tracker1.PreCenterPoint.emplace_back(100, 100);
  tracker1.assignid = 2;
  testReturn = tracker1.Tracking(testBox);
  int test = 100;
  if (!testReturn.empty()) {
    test = testReturn[0];
  }
  EXPECT_EQ(test, 2); }
/**
 * @brief Test case1 for Coordinate Transform
 * 
 */
TEST(TrackerTest, CoordinateTransformCase1Check) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/videos/double_simple.mp4");
  Camera h;
  Tracker t;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "video"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.objectTrackingid = t.Tracking(d.trackerBoxes);
  d.roboticRefFrame = t.roboticRefFrame;
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  EXPECT_EQ(t.roboticRefFrame[0].at(2), -0.2); }
/**
 * @brief Test case2 for Coordinate Transform
 * 
 */
TEST(TrackerTest, CoordinateTransformCase2Check) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/videos/double_simple.mp4");
  Camera h;
  Tracker t;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "video"), h.videoorimage);
  cv::Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.objectTrackingid = t.Tracking(d.trackerBoxes);
  d.roboticRefFrame = t.roboticRefFrame;
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  EXPECT_GT(t.roboticRefFrame[0].at(1), t.roboticRefFrame[1].at(1)); }

