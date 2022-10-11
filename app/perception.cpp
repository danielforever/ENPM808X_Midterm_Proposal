/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <./perception.h>
#include "opencv2/opencv.hpp"



int Camera::LoadVideo(std::string _videodirectory){
    cv::VideoCapture VideoObject(_videodirectory);

    if(!VideoObject.isOpened()){
        std::cout << "Error for opening video input!" << std::endl;
        return -1;
    }
    else{
        return 1;
    }
}


Detector::Detector(){
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

Person::Person(int idInput, int TrackerIDInput,float X_BoundingBox, float Y_BoundingBox, float X_CoorInput, float Y_CoorInput, float ConfidenceInput){

}

int main()
{
    //dummy();
    return 0;

}

