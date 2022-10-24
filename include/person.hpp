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

    
    /**
     *  @Brief Constructor for the Person object
     *
     */
    Person(vector<Mat>& preouts,vector<Mat>& curouts;);
    /**
     *  @Brief Distructor for the Person object
     *
     */
    ~Person();

};