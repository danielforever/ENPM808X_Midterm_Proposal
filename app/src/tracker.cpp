#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include "../../include/tracker.hpp"



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

array<double, 3> Tracker::CoordinateTransform(int inpx, int iny){

        array<double, 3> result = {};
        return result;
}


/**
 * @brief Tracking system
 * 
 * @return vector<string> 
 */
vector<int> Tracker::Tracking(const vector<Rect>& Boxes) {
        this->curBoxes = Boxes;
        int centerX;
        int centerY; 
        float coorDistance = 0;   
        cout<< "preid: " <<this->preid.size()<<endl;   
        cout<< "Step1" <<endl;   
        if(!this->roboticRefFrame.empty()){
                this->roboticRefFrame.clear(); 
        }
        if(this->preid.empty()){
                cout<< "Step2" <<endl; 
                for (int i=0; i < this->curBoxes.size(); i++){
                        centerX = this->curBoxes[i].x + this->curBoxes[i].width/2;
                        centerY = this->curBoxes[i].y + this->curBoxes[i].height/2;
                        cout<< "Step3.1" <<endl;
                        this->curCenterPoint.push_back(std::make_pair(centerX,centerY));
                        cout<< "Step3.2" <<endl;
                        this->curid.push_back(this->assignid);
                        this->assignid++;
                        cout<< "Step3" <<endl; 
                }
        }
        else{
                for (int i=0; i < Boxes.size(); i++){
                        centerX = Boxes[i].x + Boxes[i].width/2;
                        centerY = Boxes[i].y + Boxes[i].height/2;
                        this->curCenterPoint.push_back(std::make_pair(centerX,centerY));

                }
                
                for (int i=0; i < this->curCenterPoint.size(); i++){
                        cout << "curCenterPoint" << this->curCenterPoint.size() << endl;
                        for (int j = 0; j < this->PreCenterPoint.size(); j++){
                                coorDistance = this->DistanceCalculation(this->curCenterPoint[i].first, this->PreCenterPoint[j].first, this->curCenterPoint[i].second, this->PreCenterPoint[j].second);
                                cout << "coorDistance: " << coorDistance <<endl;
                                if(coorDistance < 15.0){
                                        //compare with other

                                        this->checkDistance.push_back(coorDistance);
                                        this->checkid.push_back(preid[j]);
                                        
                                } 
                        }
                        
                        if(this->checkDistance.empty()){
                                this->curid.push_back(this->assignid);
                                this->assignid++;    
                        }
                        else if(this->checkDistance.size()==1){
                                this->curid.push_back(this->checkid[0]);
                        }
                        else{
                                int min_value = *min_element(this->checkDistance.begin(),this->checkDistance.end());
                                auto it = find(this->checkDistance.begin(), this->checkDistance.end(), min_value);
                                int index = distance(this->checkDistance.begin(), it);
                                this->curid.push_back(this->checkid[index]);   
                        }  
                        this->checkDistance.clear();
                        this->checkid.clear();
                        }
                }
        if(this->PreCenterPoint.size()>this->assignid){
                this->assignid = this->PreCenterPoint.size();
        }
        this->PreCenterPoint.clear();
        this->PreCenterPoint = this->curCenterPoint;
        this->curCenterPoint.clear();
        this->preid.clear();
        this->preid = this->curid;
        for (auto i: this->preid)
                cout<<"test the id:" << i <<endl;
        this->curid.clear();   
        return this->preid; 
}
/**
 * @brief 
 * 
 * @return vector<float> 
 */
float Tracker::DistanceCalculation( int x1, int x2, int y1, int y2) { 
        return round(sqrt(pow(x1-x2,2)+pow(y1-y2,2))*100)/100; }