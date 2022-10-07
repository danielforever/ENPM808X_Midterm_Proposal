/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */

#pragma once

#include<iostream>
#include<vector>
#include "opencv2/opencv.hpp"

/**
 * @Brief  A class that detect and create Person object for the system
 */

class Detector 
{
    private:

        string VideoDirectory;
        std::vector<Person> PersonVectorDetector;

        /**
         *  @Brief Constructor
         *  
         *  @Param VideoDirectory Read video directory from system
         *  @Param PersonVectorDetector Save all the detected people into vector
         *
         */
        
        Detector(string videodirectory);
        /**
         *  @Brief Saving video into Reading video
         *  
         *  @Param VideoDirectory Read video directory from system
         *
         */
        void ReadVideo(string VideoDirectory);
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
         *  @Brief Calculate the center point for the person object
         *
         */
        void CoordinateTransform();
};
/**
 * @Brief  A tracker system that verified the Person object  
 */

class Tracker
{
    private:
        std::vector<Person> PersonaVectorTracker;
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
        Person(int idInput, int TrackerIDInput,float X_BoundingBox, float Y_BoundingBox float X_CoorInput, float Y_CoorInput, float ConfidenceInput)
        /**
         *  @Brief Destructor
         *
         */
        ~Person()



};
