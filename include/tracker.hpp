/**
 * @file tracker.hpp
 * @author Shantanu Aman Po-Yu
 * @brief 
 * @version 0.1
 * @date 2022-10-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>

using namespace cv;
using namespace cv::dnn;
using namespace std;



/**
 * @brief Class for Tracking the Humans
 * 
 */
class Tracker{
 public:
    /**
    *  @Param isInitialized check if the system is initial
    *  @Param curName store name id 
    *  @Param curConfidences store confident 
    *  @Param curBoxes store the bounding box information
    *  @Param preName store pervious name id 
    *  @Param preConfidences store pervious confident
    *  @Param preBoxes store pervious the bounding box information
    *  @Param distance store distance information
    * 
    */
    bool isInitialized = false;
    vector<string> curName;
    vector<float> curConfidences;
    vector<Rect> curBoxes;
    vector<string> preName;
    vector<float> preConfidences;
    vector<Rect> preBoxes;
    vector<float> distance;

    /**
     *  @Brief Constructor for Tracker
     *
     */
    Tracker();
    /**
     *  @Brief Destructor for Tracker
     *
     */
    ~Tracker();
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    vector<string> Tracking(const vector<Rect>& Boxes);
    /**
     *  @Brief Calculate the distance between two dots for the detected object
     *
     */
    vector<float> DistanceCalculation();
};