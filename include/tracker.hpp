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
#include <cmath>
#include <array>

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
    *  @Param curid store name id 
    *  @Param curBoxes store the bounding box information
    *  @Param preid store pervious name id 
    *  @Param allDistance store distance information
    *  @Param curCenterPoint store the center point of the objects
    *  @Param assignid keep track of the id assigned
    * 
    */
    bool isInitialized = false;
    vector<int> curid;
    vector<Rect> curBoxes;
    vector<int> preid;
    vector<int> checkDistance;
    vector<int> checkid;
    vector<int> keepid;
    vector<pair<int,int>> curCenterPoint;
    vector<pair<int,int>> PreCenterPoint;
    int assignid = 0;

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
    vector<int> Tracking(const vector<Rect>& Boxes);
    /**
     *  @Brief Calculate the distance between two dots for the detected object
     *
     */
    float DistanceCalculation( int x1, int x2, int y1, int y2);
    /**
     *  @Brief Transform the coordinate to robot's reference frame
     *
     */
    array<double, 3> CoordinateTransform(int x, int y);


};