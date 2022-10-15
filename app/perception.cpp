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

Person::Person(int _idInput, int _TrackerIDInput,float _X_BoundingBox, float _Y_BoundingBox, float _X_CoorInput, float _Y_CoorInput, float _ConfidenceInput){
    id = _idInput;
    TrackerID = _TrackerIDInput;
    Confidence = _ConfidenceInput;
    
}

int main()
{
    return 0;

}

