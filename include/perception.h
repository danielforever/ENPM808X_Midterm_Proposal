/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */

#pragma once

#include<iostream>
#include<vector>
#include "opencv2/opencv.hpp"

class Person
{
    private:
        /**
         *  @Brief Compare the coordinate to check whether this object had appeared 
         *
         */
        int id;
        int TrackerID;
        std::pair <float,float> CenterPoint;
        std::vector<float> BoundingCoordinates;
        float Confidence;

    public:
        /**
         *  @Brief Constructor
         *  
         *  @Param id an ID for a detected person
         *  @Param TrackerID an ID that gave in tracker function
         *  @Param CenterPoint add the center point for every object
         *  @Param BoundingCoordinates 
         *  @Param Confidence cofidence for the detected person
         *
         */
        Person(int _idInput, int _TrackerIDInput,float _X_BoundingBox, float _Y_BoundingBox, float _X_CoorInput, float _Y_CoorInput, float _ConfidenceInput);
        /**
         *  @Brief Destructor
         *
         */
        ~Person();



};

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
 * @Brief  A class that detect and create Person object for the system
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
         *  @Brief Run the object detection function to retreat the obstacles
         *
         */
        void ScanFrame();
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
         *  @Brief Delete the Object Person that existed in the perivous image 
         *
         */
        void DeletePerson();
};
/**
 * @Brief  An object that is person
 */


