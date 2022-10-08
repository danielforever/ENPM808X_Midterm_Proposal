/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <iostream>
#include <lib.hpp>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;


void Camera::LoadVideo(string videodirectory){
    VideoCapture VideoObject(videodirectory);

    if(!VideoObject.isOpened()){
        cout << "Error for opening video input!" << endl;
        return -1;
    }
    else{
        
    }
}

Detector::Detector(){

}

void CreatObjectPerson(){

}

int main()
{
    dummy();
    return 0;

}
