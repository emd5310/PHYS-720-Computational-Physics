#ifndef ROOTFINDERS_H
#define ROOTFINDERS_H

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#include <Eigen/Core>

namespace RootFinders{

    // Take in a vector of initial guesses, find roots for all of them
    // Return in the same order as they are found
    std::vector<double> NewtonsMethod(const std::function<double(double)>& func,
                                      const std::function<double(double)>& func_prime,
                                      const std::vector<double>& guesses, double tolerance);

    // Works the same as Newton's, but it's a vector of pairs that represent the x_1 and x_2 range
    std::vector<double> BisectionMethod(const std::function<double(double)>& func,
                                        const std::vector<std::pair<double, double>>& guesses, double tolerance);

}

#endif
