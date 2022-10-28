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
  Camera2.LoadVideo(video2.GetVideoDirectory(),"video");
  
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
  cv::VideoCapture cap3 = Camera2.LoadVideo(video2.GetVideoDirectory(),"video");
  Detector trackerObject(cap3,"video");
  EXPECT_EQ(trackerObject.outputFile, "result.avi");
}

/**
 * @brief Testing the Detector Constructor with the image route
 * 
 */

TEST(DetectorTest, DetectorConstructorImageTest) {
  std::string image_path = "assets/images/pedestrian_single.jpg";
  image1.SetVideoDirectory(image_path);
  cv::VideoCapture cap3 = Camera3.LoadVideo(image1.GetVideoDirectory(),"image");
  Detector trackerObject(cap3,"image");
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
  cv::VideoCapture cap2 = Camera2.LoadVideo(video2.GetVideoDirectory(),"video");
  Detector trackerObject(cap2,"video");
  //trackerObject.~Detector();
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
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  string test; 
  if(!d.classes.empty()){
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
  cv::VideoCapture cap2 = Camera2.LoadVideo(video2.GetVideoDirectory(),"video");
  Detector detectorObject(cap2,"video");
  detectorObject.getOutputsNames();
  string classesFile = "../cfg/coco.names";
  ifstream ifs(classesFile.c_str());
  string line;
  vector<string> classtest;
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
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  string test;
  if(!d.names.empty()){
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
  Mat frame;
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
  Mat frame;
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
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.DrawBoundingBox();
  int test;
  if(!d.boxes.empty()){
    test = d.boxes[0].width;
  }

  EXPECT_EQ(test, 63); 
}
/**
 * @brief Test does the function clean the detected object
 * 
 */
TEST(DetectorTest,ClearBoxCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  int value = 1;
  if (d.boxes.empty()){
    value = 0;
  }
  cout<<"check:"<< d.boxes[0].x<<endl;
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
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.DrawBoundingBox();
  d.CleanAndDisplay();
  d.CleanAndDisplay();
  int value = 1;
  if (d.confidences.empty()){
    value = 0;
  }
  EXPECT_EQ(value, 0);
}
/**
 * @brief Testing the Tracker
 * 
 */
// Tracker system1_tracker;

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
// TEST(TrackerTest, TrackerDestructor) {
//   Tracker trackerObject;
//   trackerObject.~Tracker();
//   EXPECT_EQ(trackerObject.isInitialized, false);
// }
/**
 * @brief Test case for Distance Calculation
 * 
 */
TEST(TrackerTest, DistanceCalculationCheck) {
  Tracker tracker1;
  float test = 5;
  EXPECT_GT(tracker1.DistanceCalculation(5,2,9,5), test);
}
/**
 * @brief Test case for Tracking Calculation
 * 
 */
// TEST(Number, TrackingFunctionCheck) {
//   a.SetVideoDirectory("assets/videos/double_person.mp4");
//   h.LoadImage(a.GetVideoDirectory());
//   cv::VideoCapture cap = h.LoadVideo(a.GetVideoDirectory(), "video");
//   Detector d(cap, h.videoorimage);
//   d.getOutputsNames();
//   Mat frame;
//   d.getOutputsNames();
//   d.cap >> frame;
//   d.DetectorSystem(frame);
//   t.Tracking(d.preOuts,d.curOuts);
  
//   EXPECT_EQ(t.Trackingcheck, 1); }

