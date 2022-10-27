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
    *  @Brief preOuts previous detected result of the vector
    *  @Param curOuts current detected result of the vector
    *  @Param isInitialized check if the system is initial
    *  @Param curNameIds store name id 
    *  @Param curConfidences store confident 
    *  @Param curBoxes store the bounding box information
    *  @Param preNameIds store pervious name id 
    *  @Param preConfidences store pervious confident
    *  @Param preBoxes store pervious the bounding box information
    *  @Param distance store distance information
    *  @Param Trackingcheck store the checking information for tracking function
    *  @Param deletePersoncheck check the deletePerson function
    * 
    */
    vector<Mat> preOuts;
    vector<Mat> curOuts;
    bool isInitialized = false;
    vector<int> curNameIds;
    vector<float> curConfidences;
    vector<Rect> curBoxes;
    vector<int> preNameIds;
    vector<float> preConfidences;
    vector<Rect> preBoxes;
    vector<float> distance;
    int Trackingcheck = 0;
    int deletePersoncheck = 0;

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
    int Tracking(const vector<Mat>& Frameresult);
    /**
     *  @Brief Calculate the distance for the detected object
     *
     */
    int DistanceCalculation();
    /**
     *  @Brief Delete the Object Person that existed in the perivous image
     *
     */
    int DeletePerson();

};