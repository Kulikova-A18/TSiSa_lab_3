#include "determination_method.h"

/**
* @brief optimal_passive_method
* Returns the value of the function at a given point
*
* @param x
*
* @return result unimodal function -cos(0.5 * x) - 1
*/
double unimodal_function(double x) {
    return (double)-cos(0.5 * x) - 1;
}

/**
* @brief multimodal_function
* Returns the value of the function at a given point
*
* @param x
*
* @return result multimodal function (-cos(0.5 * x) - 1) * (sin(5 * x))
*/
double multimodal_function(double x) {
    return (double) (-cos(0.5 * x) - 1) * (sin(5 * x));
}

