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
 * @brief Tracking system
 * 
 * @return vector<string> 
 */
vector<string> Tracker::Tracking(const vector<Rect>& Boxes) { 
        return this->curName; }
/**
 * @brief 
 * 
 * @return vector<float> 
 */
vector<float> Tracker::DistanceCalculation() { 
        return this->distance; }