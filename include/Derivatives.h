#ifndef DERIVATIVES_H
#define DERIVATIVES_H

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include <Eigen/Core>

namespace NumericDerivative{

    /**
     * Uses the Central Difference algorithm to take a derivative of one variable
     * @param a Beginning of range to diff' over
     * @param b End of range to diff' over
     * @param N Number of slices to use
     * @param func Function to differentiate
     * @return Vector containing the resulting values, in order from a->b
     */
    std::vector<double> CentralDifference(double a, double b, int N, const std::function<double(double)>& func);



}

#endif

