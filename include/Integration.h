#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <cmath>
#include <functional>
#include <iostream>

namespace NumericIntegration{
    // Implements the trapezoidal method of numeric integration of a definite integral
    double TrapezoidMethod(double a, double b, int N, const std::function<double(double)>& func);
    // Does the trapezoidal method, but uses an adaptive N to reach the target accuracy using the minimum number N
    double AdaptiveTrapezoidMethod(double a, double b, int N, double accuracy, const std::function<double(double)>& func);

    // Implements Simpson's method for numeric integration of a definite integral
    double SimpsonsMethod(double a, double b, int N, const std::function<double(double)>& func);
    // Does Simpson's Method, but uses an adaptive N to reach the target accuracy using the minimum number N
    double AdaptiveSimpsonsMethod(double a, double b, int N, double accuracy, const std::function<double(double)> &func,
                                  bool verbose= false);

    // Gaussian Quadrature
    double GaussianQuadrature(double a, double b, const std::function<double(double)> &func);
}

#endif