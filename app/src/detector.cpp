#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/detector.hpp"


/**
 * @brief Construct a new Detector:: Detector object
 * 
 */
Detector::Detector(cv::VideoCapture cap) {
    cv::Mat frame;
    while (cv::waitKey(1) < 0){
        cap >> frame;
        if(frame.empty()){
            std::cout << "Error no file input" << std::endl;
            break;
        }
    }
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

