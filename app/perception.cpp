/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include "../include/perception.hpp"

void Human_Tracker::SetVideoDirectory(std::string Videodirectory) {
    this->videodirectory = Videodirectory;
}

std::string Human_Tracker::GetVideoDirectory() {
    return videodirectory;
}

Human_Tracker::Human_Tracker(){} 
Human_Tracker::~Human_Tracker(){}

Camera::Camera(){}
Camera::~Camera(){}

int Camera::LoadVideo(std::string Videodirectory){
    return 1;
}

Detector::Detector(){
    isInitialized=true;
}
Detector::~Detector(){
    isInitialized=false;
}

bool Detector::DetectorSystem(){
    return true;
}

int Detector::CoordinateTransform(){
    return 0;
}

int Detector::DrawBoundingBox(){
    return 0;
}

Tracker::Tracker(){
        isInitialized=true;
}
Tracker::~Tracker(){
        isInitialized=false;
}

int Tracker::Tracking(){
    return 0;
}

int Tracker::DistanceCalculation(){
    return 0;
}

int Tracker::DeletePerson(){
    return 0;
}