#ifndef MAIN_H
#define MAIN_H

// Standard libraries
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>

// 3rd Party
#include <Eigen/Core>
#include <Eigen/Eigenvalues> // For eigenvalues
#include <Eigen/LU> // For determinants

// Project-level
#include "Derivatives.h"
#include "EigenFinders.h"
#include "LinearSystems.h"
#include "Integration.h"
#include "Interpolation.h"
#include "RootFinders.h"
#include "ThreadedIntegration.h"
#include "tests.h"

std::string print(std::string message){
    std::cout << message << std::endl;
    return message;
}

#endif