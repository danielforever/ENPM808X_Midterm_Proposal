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

