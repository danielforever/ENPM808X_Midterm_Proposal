/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */

#pragma once

#include<iostream>
#include<vector>
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
        Human_Tracker();
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
         *  @Brief Constructor
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
         *  @Brief Constructor
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
    private:

        std::vector<Person*> PersonVectorDetector;

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
        std::vector<Person*> PersonaVectorTracker;
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
