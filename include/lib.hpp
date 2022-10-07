/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma,   
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
        std::vector<Person> PersonVectorDector;

        /**
         *  @Brief Constructor
         *  
         *  @Param VideoDirectory Read video directory from system
         *
         */
        
        Detector(string videodirectory){
            VideoDirectory = videodirectory;
        }
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
         *  @Brief 
         *
         */
        void CoordinateTransform();
};
/**
 * @Brief  A tracker system that verified
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

        void DeletePerson();
};

class Person
{
    private:
        int id;
        int tracker_id;
        float center_point;
        std::vector<float> bounding_coordinates;
        float confidence;

    public:
        Person(int idInput, int TrackerIDInput, float CenterPointInput, float X_CoorInput, float Y_CoorInput, float ConfidenceInput)
        ~Person()



};
