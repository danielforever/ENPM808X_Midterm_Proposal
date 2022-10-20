/**
 * @file perception.h
 * @Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <iostream>
#include <vector>
#include "opencv2/opencv.hpp"

/**
 * @Brief  A class that starts the whole system
 */
class Human_Tracker
{
private:
    /**
     *  @Brief Create a Human Tracker class
     *
     */
    std::string videodirectory = "";

public:
    /**
     *  @Brief Constructor
     *
     */
    Human_Tracker();
    // Setter
    void setInput(std::string Videodirectory);
    // Getter
    std::string getInput();
    /**
     *  @Brief Destructor
     *
     */
    ~Human_Tracker();
};
/**
 * @Brief  A class that read images or videos from the directory
 */
class Camera
{

private:
    /**
     *
     *  @Param VideoObject This store the object of the video
     *  @Param ImageWeight Store image weight
     *  @Param ImageHeight Store image height
     *
     */
    //cv::VideoCapture VideoObject;
    float ImageWeight;
    float ImageHeight;
public:
    /**
     *
     *  @Param VideoDirectory Read video directory from system
     *
     */
    int LoadVideo();
    Camera();
    ~Camera();
};

/**
 * @Brief  A class that detect and add Person object for the vector
 */
class Detector
{

public:
    /**
     *
     *  @Param boxes Store the bounding box coordinate into a vector
     *  @Param Confidences Store the confidences into a vector
     *
     */
    std::vector<cv::Rect> boxes;
    std::vector<float> Confidences;

private:
    /**
     *  @Brief Constructor
     *
     *  @Param PersonVectorDetector Save all the detected people into vector
     *
     */
    Detector();
    /**
     *  @Brief Send to object regonition system
     *
     */
    bool DetectorSystem();
    /**
     *  @Brief To transform the cooridnate to Robot frame and calculate the center point
     *
     */
    int CoordinateTransform();
    /**
     *  @Brief Draw bounding box for the image
     *
     */
    int DrawBoundingBox();
    /**
     *  @Brief Distructor
     *
     */
    ~Detector();
};

/**
 * @Brief  A tracker system that verified the Person object
 */

class Tracker
{
private:
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    Tracker();
    ~Tracker();

    int Tracking();
    /**
     *  @Brief Compare the coordinate to check whether this object had appeared
     *
     */
    int DistanceCalculation();
    /**
     *  @Brief Delete the Object Person that existed in the perivous image
     *
     */
    int DeletePerson();
};
/**
 * @Brief  An object that is person
 */
