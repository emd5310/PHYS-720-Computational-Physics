#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <cmath>
#include <functional>

namespace NumericIntegration{
    double TrapezoidMethod(double a, double b, double N, std::function<double(double)> func);

    double SimpsonsMethod(double a, double b, double N, std::function<double(double)> func);
}

#endif