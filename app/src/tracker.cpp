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
vector<string> Tracker::Tracking(const vector<float>& Confidences, const vector<Rect>& Boxes) { 
        return this->curName; }
/**
 * @brief 
 * 
 * @return int 
 */
vector<float> Tracker::DistanceCalculation() { 
        return this->distance; }
/**
 * @brief 
 * 
 * @return int 
 */
int Tracker::DeletePerson() { return 0; }