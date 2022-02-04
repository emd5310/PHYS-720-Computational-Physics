#ifndef DERIVATIVES_H
#define DERIVATIVES_H

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include <Eigen/Core>

namespace NumericDerivative{

    // Uses the central difference method to calculate the numeric derivative of func
    std::vector<double> CentralDifference(const std::function<double(double)>& func, double x);



}

#endif

