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
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>





/**
 * @brief Class for Tracking the Humans
 * 
 */
class Tracker{
 public:
    bool isInitialized = false;
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
    virtual int Tracking();
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