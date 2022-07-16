#include "Derivatives.h"


std::vector<double> NumericDerivative::CentralDifference(double a, double b, int N, const std::function<double(double)>& func){
    double h = (b - a) / N;
    std::vector<double> result;
    result.reserve(N);

    double x = a;
    double deriv;
    for(int i = 0; i < N; i++){
        deriv = (func(x + h/2) - func(x - h/2)) / h;
        result.push_back(deriv);
        x += h;
    }
    return result;
}

