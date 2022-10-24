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

    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    Tracker();
    ~Tracker();
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    int Tracking(const vector<Mat>& Preouts,const vector<Mat>& Curouts);
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