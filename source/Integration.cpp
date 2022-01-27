#include "Integration.h"

double NumericIntegration::TrapezoidMethod(double a, double b, double N, std::function<double(double)> func){
    double h = (b - a) / N;
    double EndPoints = (1.0/2.0) * (func(a) + func(b));

    double RunningSum;
    for(int k = 1; k < N; k++){
        RunningSum += func(a + k * h);
    }

    return h * (EndPoints + RunningSum);
}

double NumericIntegration::SimpsonsMethod(double a, double b, double N, std::function<double(double)> func){
    double h = (b - a) / N;
    double EndPoints = func(a) + func(b);

    double OddRunningSum;
    for(int k = 1; k <= (N-1); k+=2){
        OddRunningSum += func(a + k * h);
    }

    double EvenRunningSum;
    for(int k = 2; k <= (N-2); k+=2){
        EvenRunningSum += func(a + k * h);
    }

    return (1.0/3.0) * h * (EndPoints + 4 * OddRunningSum + 2 * EvenRunningSum);
}