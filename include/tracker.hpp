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
#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <array>
#include <utility>

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/dnn.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>



#define PI 3.14159265

/**
 * @brief A class for Tracking the Humans
 * 
 */
class Tracker {
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
    std::vector<int> curid;
    std::vector<cv::Rect> curBoxes;
    std::vector<int> preid;
    std::vector<int> checkDistance;
    std::vector<int> checkid;
    std::vector<int> keepid;
    std::vector<std::pair<int, int>> curCenterPoint;
    std::vector<std::pair<int, int>> PreCenterPoint;
    int assignid = 0;
    std::vector<std::array<double, 3>> roboticRefFrame;

    /**
     * @brief Construct a new Tracker object
     * 
     */
    Tracker();
    /**
     * @brief Destroy the Tracker object
     * 
     */
    ~Tracker();
    /**
     * @brief Compare the coordinate to check whether this object had appeared
     * 
     * @param Boxes 
     * @return std::vector<int> 
     */
    std::vector<int> Tracking(const std::vector<cv::Rect>& Boxes);
    /**
     * @brief Calculate the distance between two dots for the detected object
     * 
     * @param x1 
     * @param x2 
     * @param y1 
     * @param y2 
     * @return float 
     */
    float DistanceCalculation(int x1, int x2, int y1, int y2);
    /**
     * @brief Transform the coordinate to robot's reference frame
     * 
     * @param x 
     * @param y 
     * @return std::array<double, 3> 
     */
    std::array<double, 3> CoordinateTransform(int x, int y);
};
