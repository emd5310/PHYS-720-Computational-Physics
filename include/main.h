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
#include "EigenFinders.h"
#include "LinearSystems.h"
#include "Integration.h"
#include "Interpolation.h"
#include "RootFinders.h"

std::string print(std::string message){
    // Convenient wrapper for cout
    std::cout << message << std::endl;
    return message;
}

double SimpleQuadratic(double x){
    return std::pow(x, 2);
}

double Polynomial(double x){
    return 924*std::pow(x,6) - 2772*std::pow(x,5) + 3150*std::pow(x,4) -
            1680*std::pow(x,3) + 420*std::pow(x,2) - 42*x + 1;
}

double PolynomialPrime(double x){
    return 42*(132*std::pow(x,5) - 330*std::pow(x,4) + 300*std::pow(x,3) -
            120*std::pow(x,2) + 20*x -1);
}

double WeirdPoly(double x){
    return 2.0 * std::pow(x, 3) + 5.0 * std::pow(x, 2) - 11.2 * x;
}



#endif