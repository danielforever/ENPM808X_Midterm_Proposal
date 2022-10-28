#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/tracker.hpp"



/**
 * @brief Construct a new Tracker:: Tracker object
 * 
 */
Tracker::Tracker() {
        
}
Tracker::~Tracker() {
        
}

/**
 * @brief Tracking system
 * 
 * @return vector<string> 
 */
vector<int> Tracker::Tracking(const vector<Rect>& Boxes) {
        return this->preid; 
}
/**
 * @brief 
 * 
 * @return vector<float> 
 */
float Tracker::DistanceCalculation( int x1, int x2, int y1, int y2) { 
        return round(sqrt(pow(x1-x2,2)+pow(y1-y2,2))*100)/100; }