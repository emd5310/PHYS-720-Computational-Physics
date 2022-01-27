#ifndef MAIN_H
#define MAIN_H

// Standard libraries
#include <cmath>
#include <iostream>
#include <string>

// 3rd Party
#include <Eigen/Core>
#include <Eigen/Eigenvalues> // For eigenvalues
#include <Eigen/LU> // For determinants

// Project-level
#include "LinearSystems.h"
#include "Integration.h"
#include "Interpolation.h"

std::string print(std::string message){
    // Convenient wrapper for cout
    std::cout << message << std::endl;
    return message;
}

double SimpleQuadratic(double x){
    return std::pow(x, 2);
}



#endif