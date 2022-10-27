#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/tracker.hpp"



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
vector<string> Tracker::Tracking(const vector<Mat>& Frameresult) { return 0; }
/**
 * @brief 
 * 
 * @return int 
 */
vector<float> Tracker::DistanceCalculation() { 
        return 0; }
/**
 * @brief 
 * 
 * @return int 
 */
int Tracker::DeletePerson() { return 0; }