/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <iostream>
#include <perception.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


int Camera::LoadVideo(string videodirectory){
    VideoCapture VideoObject(videodirectory);

    if(!VideoObject.isOpened()){
        cout << "Error for opening video input!" << endl;
        return -1;
    }
    else{
        return 1;
    }
}


Detector::Detector(){
    return 0;
}

void Detector::CreatObjectPerson(){

}

void Detector::ScanFrame(){

}

void Detector::CoordinateTransform(){

}

void Detector::DrawBoundingBox(){

}

void Tracker::Tracking(){

}

void Tracker::DeletePerson(){

}

void Person::Person(){

}

int main()
{
    //dummy();
    return 0;

}

