/**
 * @file tracker.cpp
 * @author Shantanu Po-Yu Aman
 * @brief Implementation of the Tracker Class Methods
 * @version 0.1
 * @date 2022-10-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../../include/tracker.hpp"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>





/**
 * @brief Construct a new Tracker:: Tracker object
 * 
 */
Tracker::Tracker() {
        this->isInitialized = true;
}
Tracker::~Tracker() {
        this->isInitialized = false;
}

std::array<double, 3> Tracker::CoordinateTransform(int inpx, int iny) {
        double z = -0.2;
        double p = 90.5 + (iny - 208)*70/416.0;
        double a = 45 - (inpx- 128)*90/256.0;
        double r = z/cos(p * PI / 180.0);
        double Invr = r * sin(p * PI / 180.0);
        double x = Invr * cos(a * PI / 180.0);
        double y = Invr * sin(a * PI / 180.0);
        std::array<double, 3> result = {x, y, z};
        return result;
}


/**
 * @brief Tracking system
 * 
 * @return vector<string> 
 */
std::vector<int> Tracker::Tracking(const vector<cv::Rect>& Boxes) {
        this->curBoxes = Boxes;
        int centerX;
        int centerY;
        std::cout<< "preid: " << this->preid.size() << std::endl;
        std::cout<< "Step1" <<std::endl;
        if (!this->roboticRefFrame.empty()) {
                this->roboticRefFrame.clear();
        }
        if (this->preid.empty()) {
                std::cout<< "Step2" <<std::endl;
                for (int i=0; i < this->curBoxes.size(); i++) {
                        centerX = this->curBoxes[i].x +
                                        this->curBoxes[i].width/2;
                        centerY = this->curBoxes[i].y +
                                        this->curBoxes[i].height/2;
                        std::cout<< "Step3.1" <<std::endl;
                        this->curCenterPoint.push_back(
                                std::make_pair(centerX, centerY));
                        std::cout<< "Step3.2" <<std::endl;
                        this->curid.push_back(this->assignid);
                        this->assignid++;
                        std::cout<< "Step3" <<std::endl;
                }
        } else {
                for (int i=0; i < Boxes.size(); i++) {
                        centerX = Boxes[i].x + Boxes[i].width/2;
                        centerY = Boxes[i].y + Boxes[i].height/2;
                        this->curCenterPoint.push_back(
                                std::make_pair(centerX, centerY));
                }
                for (int i=0; i < this->curCenterPoint.size(); i++) {
                        std::cout << "curCenterPoint" <<
                                this->curCenterPoint.size() << std::endl;
                        for (int j = 0; j < this->PreCenterPoint.size(); j++) {
                                float coorDistance = this->DistanceCalculation(
                                        this->curCenterPoint[i].first,
                                        this->PreCenterPoint[j].first,
                                        this->curCenterPoint[i].second,
                                        this->PreCenterPoint[j].second);
                                std::cout  << "coorDistance: "
                                                << coorDistance <<std::endl;
                                if (coorDistance < 15.0) {
                                        // compare with other
                                        this->checkDistance.push_back(
                                                coorDistance);
                                        this->checkid.push_back(preid[j]);
                                }
                        }
                        if (this->checkDistance.empty()) {
                                this->curid.push_back(this->assignid);
                                this->assignid++;
                        } else if (this->checkDistance.size() == 1) {
                                this->curid.push_back(this->checkid[0]);
                        } else {
                                int min_value = *min_element(
                                                this->checkDistance.begin(),
                                                this->checkDistance.end());
                                auto it = find(this->checkDistance.begin(),
                                                this->checkDistance.end(),
                                                min_value);
                                int index = distance(
                                                this->checkDistance.begin(),
                                                it);
                                this->curid.push_back(this->checkid[index]);
                        }
                        this->checkDistance.clear();
                        this->checkid.clear();
                        }
                }
        if (this->PreCenterPoint.size() > this->assignid) {
                this->assignid = this->PreCenterPoint.size();
        }
        this->PreCenterPoint.clear();
        for (int i=0; i < this->curCenterPoint.size(); i++) {
                std::cout << "id: " << this->curid[i] <<std::endl;
                std::cout  << "2dx: " <<
                this->curCenterPoint[i].first <<
                " 2dy: " << this->curCenterPoint[i].second << std::endl;
                this->roboticRefFrame.push_back(this->CoordinateTransform(
                                        this->curCenterPoint[i].first,
                                        this->curCenterPoint[i].second));
                std::cout  << "3dx: " <<
                 this->roboticRefFrame[i].at(0) <<
                 " 3dy: " << this->roboticRefFrame[i].at(1) <<
                  " 3dz: " << this->roboticRefFrame[i].at(2) << std::endl;
        }
        this->PreCenterPoint = this->curCenterPoint;
        this->curCenterPoint.clear();
        this->preid.clear();
        this->preid = this->curid;
        for (auto i : this->preid)
                std::cout <<"test the id:" << i <<std::endl;
        this->curid.clear();
        return this->preid;
}
/**
 * @brief 
 * 
 * @return vector<float> 
 */
float Tracker::DistanceCalculation(int x1, int x2, int y1, int y2) {
        return round(sqrt(pow(x1-x2, 2)+pow(y1-y2, 2))*100)/100; }
