#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <cmath>
#include <functional>
#include <iomanip> // For setting the cout precision
#include <iostream> // For cout

namespace NumericIntegration{
    double TrapezoidMethod(double a, double b, double N, std::function<double(double)> func);
    double AdaptiveTrapezoidMethod(double a, double b, double N, double accuracy, std::function<double(double)> func);

    double SimpsonsMethod(double a, double b, double N, std::function<double(double)> func);
    double AdaptiveSimpsonsMethod(double a, double b, double N, double accuracy, std::function<double(double)> func);
}

#endif