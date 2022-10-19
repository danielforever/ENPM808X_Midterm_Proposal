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

#include<iostream>
#include<vector>
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

    public:

        /**
         *  @Brief Constructor
         *
         */
        Human_Tracker(std::string videodirectory);
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
        cv::VideoCapture VideoObject;
        float ImageWeight;
        float ImageHeight;



    public:
        /**
         *  
         *  @Param VideoDirectory Read video directory from system
         *
         */    
        int LoadVideo(std::string videodirectory);

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
    	std::vector<Rect> boxes;
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
         *  @Brief Create an object Person for every detected person
         *
         */        
        void CreatObjectPerson();
        /**
         *  @Brief To transform the cooridnate to Robot frame and calculate the center point
         *
         */
        void CoordinateTransform();
        /**
         *  @Brief Draw bounding box for the image
         *
         */
        void DrawBoundingBox();

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
        void Tracking();
        /**
         *  @Brief Compare the coordinate to check whether this object had appeared 
         *
         */
        void DistanceCalculation();
        /**
         *  @Brief Delete the Object Person that existed in the perivous image 
         *
         */
        void DeletePerson();
};
/**
 * @Brief  An object that is person
 */
