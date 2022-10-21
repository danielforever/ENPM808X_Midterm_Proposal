/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/perception.hpp"

/**
 * @brief set the video directory that will be required for the loading video
 * 
 * @param Videodirectory for the video directory 
 */
void Human_Tracker::SetVideoDirectory(std::string Videodirectory) {
  this->videodirectory = Videodirectory;
}
/**
 * @brief getting the path of the video directory
 * 
 * @return std::string returning the video directory
 */
std::string Human_Tracker::GetVideoDirectory() { return videodirectory; }
/**
 * @brief Construct a new Human_Tracker::Human_Tracker object
 * 
 */
Human_Tracker::Human_Tracker() {
    isInitialized = true;
    Camera camera;
    std::string path = "../assets/images/pedestrian_single.jpg";
    camera.LoadImage(path);}
/**
 * @brief Destroy the Human_Tracker::Human_Tracker object
 * 
 */
Human_Tracker::~Human_Tracker() { isInitialized = false; }
/**
 * @brief Construct a new Camera:: Camera object
 * 
 */
Camera::Camera() {}
Camera::~Camera() {}
/**
 * @brief 
 * 
 * @param Videodirectory Loadin the Video Directory
 * @return int 
 */
int Camera::LoadVideo(std::string Videodirectory) { return 1; }
/**
 * @brief 
 * 
 * @param path giving the path
 * @return int 
 */
int Camera::LoadImage(std::string path) {
    std::string image_path = cv::samples::findFile(path);
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    if (img.empty()) {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = cv::waitKey(0);  // Wait for a keystroke in the window
    if (k == 's') {
        imwrite("starry_night.png", img);
    }
    return 0;
}

/**
 * @brief Construct a new Detector:: Detector object
 * 
 */
Detector::Detector() {
    isInitialized = true;
}
/**
 * @brief Destroy the Detector:: Detector object
 * 
 */
Detector::~Detector() {
    isInitialized = false;
}
/**
 * @brief Construct a new Detector:: Detector object
 * 
 * @param path 
 */
Detector::Detector(std::string path) {
    isInitialized = true;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Detector::DetectorSystem() { return 0; }

int Detector::CoordinateTransform() { return 0; }

int Detector::DrawBoundingBox() { return 0; }


/**
 * @brief Construct a new Tracker:: Tracker object
 * 
 */
Tracker::Tracker() {
        isInitialized = true;
}
Tracker::~Tracker() {
        isInitialized = false;
}

/**
 * @brief Tracking constructor
 * 
 * @return int 
 */
int Tracker::Tracking() { return 0; }
/**
 * @brief 
 * 
 * @return int 
 */
int Tracker::DistanceCalculation() { return 0; }
/**
 * @brief 
 * 
 * @return int 
 */
int Tracker::DeletePerson() { return 0; }
