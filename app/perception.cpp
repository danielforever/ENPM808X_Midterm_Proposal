/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include "../include/perception.hpp"

void Human_Tracker::setInput(std::string Videodirectory) {
    this->videodirectory = Videodirectory;
}

std::string Human_Tracker::getInput() {
    return videodirectory;
}

Human_Tracker::Human_Tracker(){} 
Human_Tracker::~Human_Tracker(){}