#ifndef MAIN_H
#define MAIN_H

// Standard libraries
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// 3rd Party
#include <Eigen/Core>
#include <Eigen/Eigenvalues> // For eigenvalues
#include <Eigen/LU> // For determinants

// Project-level
#include "EigenFinder.h"
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

double WeirdPoly(double x){
    return 2.0 * std::pow(x, 3) + 5.0 * std::pow(x, 2) - 11.2 * x;
}



#endif