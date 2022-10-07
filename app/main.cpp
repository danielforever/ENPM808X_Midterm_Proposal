/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <iostream>
#include <lib.hpp>

using namespace std;
using namespace cv;


void Camera::LoadVideo(string videodirectory){
    VideoCapture cap(videodirectory);

    if(!cap.isOpened()){
        cout << "Error for opening video input!" << endl;
        return -1;
    }
}

int main()
{
    dummy();
    return 0;

}
