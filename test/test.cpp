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
Camera Camera3;
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
std::string video_path = "assets/videos/double_person.mp4";
cv::VideoCapture cap2 = Camera2.LoadVideo(video1.GetVideoDirectory(),"video");
cv::VideoCapture cap3 = Camera3.LoadVideo(video1.GetVideoDirectory(),"video");
TEST(Number, VideoObjectCheck) {
  Human_Tracker video2;
  video2.SetVideoDirectory(video_path);
  cv::VideoCapture cap = Camera2.LoadVideo(video2.GetVideoDirectory(),"video");
  EXPECT_EQ(Camera2.videoorimage, "video");
}
/**
 * @brief Testing the Detector Constructor
 * 
 */
TEST(Detector, DetectorConstructor1) {
  Detector trackerObject(cap2,"video");
  EXPECT_EQ(trackerObject.isInitialized, true);
}

/**
 * @brief Testing the Detector Destructor 
 * 
 */
TEST(Detector, DetectorDestructor2) {
  Detector* trackerObject = new Detector(cap2,"video");
  delete trackerObject;
  EXPECT_EQ(trackerObject->isInitialized, false);
}
/**
 * @brief Read the label name from coco.names
 * 
 */
TEST(Detector, getOutputsNamesCheckReadFile) {
  Detector* detectorObject = new Detector(cap2,"video");
  detectorObject->getOutputsNames();
  ifstream in(detectorObject->fileName.c_str());
  bool test = true;
  if(!in){
    test = false;
  }
  delete detectorObject;
  EXPECT_EQ(test, true); 
}

/**
 * @brief Test the label name is what we expect from coco.names
 * 
 */
TEST(Detector, getOutputsNamesCheckFileContaint) {
  Detector* detectorObject = new Detector(cap2,"video");
  detectorObject->getOutputsNames();
  ifstream in(detectorObject->fileName.c_str());
  in.seekg(0, std::ios::end);
  size_t size = in.tellg();
  delete detectorObject;
  string classesFile = "../cfg/coco.names";
  ifstream ifs(classesFile.c_str());
  ifs.seekg(0, std::ios::end);
  size_t sizetest = ifs.tellg();
  EXPECT_EQ(size, sizetest); 
}
/**
 * @brief Testing the DetectorSystem for Detector Class
 * 
 */
// TEST(Detector, DetectObjectCheck0) {
//   Human_Tracker* a = new Human_Tracker;
//   Camera* h = new Camera;
//   a->SetVideoDirectory("assets/videos/double_person.mp4");

//   h->LoadImage(a->GetVideoDirectory());
//   cv::VideoCapture cap = h->LoadVideo(a->GetVideoDirectory(), "video");
//   Detector* d = new Detector(cap, h->videoorimage);
//   d->DetectorSystem
//   EXPECT_EQ(trackerObject.isInitialized, 1);
//   }

/**
 * @brief Coordinate system transformation tests 
 * 
 */

//   Mat frame1;
//   Tracker t;

// TEST(FrameSize, resizeCheck) {
//   a.SetVideoDirectory("assets/videos/double_person.mp4");
//   h.LoadImage(a.GetVideoDirectory());
//   cv::VideoCapture cap = h.LoadVideo(a.GetVideoDirectory(), "video");
//   Detector d(cap, h.videoorimage);
//   d.cap >> frame1;
//   int width = frame1.cols;
//   int height = frame1.rows;
//   float yoloPixel = 416.0;
//   float maxPixel = max(width, height);
//   float ratio = yoloPixel/maxPixel;
//   int test = int(((416 - int(round(width * ratio))) % 32 )/2);
//   EXPECT_EQ(d.resizeWidth, test);
// }
/**
 * @brief Bouding box testing 
 * 
 */

// String modelConfiguration = "cfg/yolov3.cfg";
// String modelWeights = "cfg/yolov3.weights";
// Mat frame, blob;

// TEST(Number, DrawBoundingBoxCheck) {
//   std::string image_path = "assets/videos/double_person.mp4";
//   a.SetVideoDirectory(image_path);
//   h.LoadImage(a.GetVideoDirectory());
//   cv::VideoCapture cap = h.LoadVideo(a.GetVideoDirectory(), "video");
//   Detector d(cap, h.videoorimage);
//   d.cap >> frame;
//   d.DetectorSystem(frame);
//   int test = d.DrawBoundingBoxcheck;

//   EXPECT_EQ(test, 1); 
// }

/**
 * @brief Bouding box testing 
 * 
 */
// TEST(checkFlag, drawPredCheck) {
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

//   EXPECT_EQ(d.drawPredcheck, 1);
// }
/**
 * @brief Test case for Detector destructor
 * 
 */
// TEST(DetectorTest, DetectorTestDestructor) {
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
//   EXPECT_EQ(d.isInitialized, false);
// }
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
