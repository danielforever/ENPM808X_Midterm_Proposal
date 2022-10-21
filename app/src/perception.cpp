/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/perception.hpp"


using namespace cv;

void Human_Tracker::SetVideoDirectory(std::string Videodirectory) {
  this->videodirectory = Videodirectory;
}

std::string Human_Tracker::GetVideoDirectory() { return videodirectory; }

Human_Tracker::Human_Tracker() { 
    isInitialized = true;
    Camera camera;
    std::string path="../assets/images/pedestrian_single.jpg";
    camera.LoadImage(path);
 }
Human_Tracker::~Human_Tracker() { isInitialized = false; }

Camera::Camera() {}
Camera::~Camera() {}

int Camera::LoadVideo(std::string Videodirectory) { return 1; }

int Camera::LoadImage(std::string path){
  
    std::string image_path = samples::findFile(path);
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    if(k == 's')
    {
        imwrite("starry_night.png", img);
    }
    return 0;
}


Detector::Detector(){
    isInitialized=true;
}
Detector::~Detector(){
    isInitialized=false;
}


bool Detector::DetectorSystem() { return true; }

int Detector::CoordinateTransform() { return 0; }

int Detector::DrawBoundingBox() { return 0; }



Tracker::Tracker(){
        isInitialized=true;
}
Tracker::~Tracker(){
        isInitialized=false;
}


int Tracker::Tracking() { return 0; }

int Tracker::DistanceCalculation() { return 0; }

int Tracker::DeletePerson() { return 0; }