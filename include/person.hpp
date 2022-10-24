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
 * @brief Class for Humans object
 * 
 */
class Person{
 public:
    vector<Mat>& preOuts;
    vector<Mat>& curOuts;
    float confidences;
    float distance;
    float xCoordinate;
    float yCoordinate;
    float xBoundingBox;
    float yBoundingBox;

    /**
     *  @Brief Constructor for the Person object
     *
     */
    Person(const vector<Mat>& preouts, const vector<Mat>& curouts);
    /**
     *  @Brief Distructor for the Person object
     *
     */
    ~Person();

};