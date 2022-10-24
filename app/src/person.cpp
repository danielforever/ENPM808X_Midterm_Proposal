/**
 * @file camera.hpp
 * @author Po-Yu Shantanu Aman 
 * @brief
 * @version 0.1
 * @date 2022-10-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../../include/person.hpp"

#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>

/**
 * @brief Construct a new Person:: Person object
 *
 */
Person::Person(const vector<Mat>& preouts, const vector<Mat>& curouts) {
    isInitialized = true;
}
Person::~Person() {
    isInitialized = false;
}
