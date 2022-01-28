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

double NumericIntegration::AdaptiveTrapezoidMethod(double a, double b, double N, double accuracy, std::function<double(double)> func){
    double h = (b - a) / N;
    double EndPoints = (1.0/2.0) * (func(a) + func(b));

    double RunningSum;
    for(int k = 1; k < N; k++){
        RunningSum += func(a + k * h);
    }

    double InitialIntegral = h * (EndPoints + RunningSum); // Now we go through and add on to increase accuracy
    double RefinedIntegral = InitialIntegral;

    // This is our initial guess - we now increase N and decrease h until we hit our target accuracy
    do{
        InitialIntegral = RefinedIntegral;
        RefinedIntegral = (1.0/2.0)*InitialIntegral;

        N = 2.0 * N;
        h = h / 2.0;
        RunningSum = 0;

        // We're only interested in the odd numbered terms now- the others are included by adding onto our previous result
        for(int k = 1; k < N; k+=2){
            RunningSum += func(a + k * h);
        }
        RefinedIntegral += h * RunningSum;

        std::cout << "Adjustment term: " << h * RunningSum << std::endl;
        std::cout << "Refined is: " << RefinedIntegral << std::endl;
        std::cout << "Error is: " << (1.0/3.0)*(InitialIntegral - RefinedIntegral) << "\n" << std::endl;

    }while(accuracy < (1.0/3.0)*(InitialIntegral - RefinedIntegral));

    return RefinedIntegral;
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

double NumericIntegration::AdaptiveSimpsonsMethod(double a, double b, double N, double accuracy, std::function<double(double)> func){
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

    double Integral = (1.0/3.0) * h * (EndPoints + 4 * OddRunningSum + 2 * EvenRunningSum);
    double RefinedIntegral;

    return RefinedIntegral;
}