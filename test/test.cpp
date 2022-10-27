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



TEST(Number, VideoObjectCheck) {
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
TEST(Detector, DetectorConstructorVideoTest) {
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

TEST(Detector, DetectorConstructorImageTest) {
  Human_Tracker image1;
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
TEST(Detector, DetectorDestructor2) {
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
TEST(Detector, getOutputsNamesCheckReadFile) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  EXPECT_EQ(d.classes[0], "person");
}

/**
 * @brief Read the label name size is equal to coco.names
 * 
 */
TEST(Detector, getOutputsNamesCheckFileContaint) {
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
TEST(Detector, DetectObjectCheck0) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  EXPECT_EQ(d.names[0], "yolo_82");
  }

/**
 * @brief Test the portion of width that needed to be resize 
 * 
 */

TEST(FrameSize, boxSizeWidthCheck) {
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

TEST(FrameSize, boxSizeHeightCheck) {
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


TEST(Number, DrawBoundingBoxCheck) {
  Human_Tracker b;
  b.SetVideoDirectory("../assets/images/pedestrian_single.jpg");
  Camera h;
  Detector d(h.LoadVideo(b.GetVideoDirectory(), "image"), h.videoorimage);
  Mat frame;
  d.getOutputsNames();
  d.cap >> frame;
  d.DetectorSystem(frame);
  d.DrawBoundingBox();

  EXPECT_EQ(d.boxes[0].width, 63); 
}

/**
 * @brief Test the center point for the detected object
 * 
 */

/**
 * @brief Testing the Tracker
 * 
 */
// Tracker system1_tracker;

/**
 * @brief Construct a new TEST object
 * To check if the constructor is being called
 */
// TEST(TrackerTest, TrackerConstructor) {
//   Tracker trackerObject;
//   EXPECT_EQ(trackerObject.isInitialized, true);
// }
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
// TEST(Distance, DistanceCalculationCheck) {
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
//   t.DeletePerson();
//   t.DistanceCalculation();
//   d.DrawBoundingBox();
//   d.~Detector();
//   float test = 0;
//   EXPECT_GT(system1_tracker.distance[0], test);
// }
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

/**
 * @brief Testing case for Deleted Person
 * 
 */
// TEST(Number, DeletePersonCheck) {
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
//   t.DeletePerson();

//   EXPECT_EQ(system1_tracker.DeletePerson(), 3);
// }
