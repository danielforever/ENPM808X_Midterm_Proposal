/* Copyright 2022
 * Author(s) Po-Yu Huang, Aman Sharma, Shantanu
 *
 */
#include <./perception.hpp>

void Human_Tracker::setInput(std::string Videodirectory){
    videodirectory = Videodirectory;
    
}

std::string Human_Tracker::getInput(){
    return videodirectory;
}

