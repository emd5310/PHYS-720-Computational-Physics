#include "Integration.h"

double NumericIntegration::TrapezoidMethod(double a, double b, int N, const std::function<double(double)>& func){
    double h = (b - a) / N;
    double EndPoints = (1.0/2.0) * (func(a) + func(b));

    double RunningSum = 0;
    for(int k = 1; k < N; k++){
        RunningSum += func(a + k * h);
    }

    return h * (EndPoints + RunningSum);
}

double NumericIntegration::AdaptiveTrapezoidMethod(double a, double b, int N, double accuracy, const std::function<double(double)>& func){
    double h = (b - a) / N;
    double EndPoints = (1.0/2.0) * (func(a) + func(b));

    double RunningSum = 0;
    for(int k = 1; k < N; k++){
        RunningSum += func(a + k * h);
    }

    double InitialIntegral = h * (EndPoints + RunningSum); // Now we go through and add on to increase accuracy
    double RefinedIntegral = InitialIntegral;
    
    double Error;
    // This is our initial guess - we now increase N and decrease h until we hit our target accuracy
    do{
        InitialIntegral = RefinedIntegral;
        RefinedIntegral = (1.0/2.0)*InitialIntegral;

        N *= 2.0;
        h /= 2.0;
        RunningSum = 0;

        // We're only interested in the odd numbered terms now- the others are included by adding onto our previous result
        for(int k = 1; k < N; k+=2){
            RunningSum += func(a + k * h);
        }
        RefinedIntegral += h * RunningSum;

        Error = (1.0/3.0)*std::abs((RefinedIntegral - InitialIntegral));

    }while(accuracy < Error);

    // std::cout << "Result: " << RefinedIntegral << std::endl;
    // std::cout << "Error: " << Error << std::endl;

    return RefinedIntegral;
}

double NumericIntegration::SimpsonsMethod(double a, double b, int N, const std::function<double(double)>& func){
    double h = (b - a) / N;
    double EndPoints = func(a) + func(b);

    double OddRunningSum = 0;
    for(int k = 1; k <= (N-1); k+=2){
        OddRunningSum += func(a + k * h);
    }

    double EvenRunningSum = 0;
    for(int k = 2; k <= (N-2); k+=2){
        EvenRunningSum += func(a + k * h);
    }

    return (1.0/3.0) * h * (EndPoints + 4 * OddRunningSum + 2 * EvenRunningSum);
}

double NumericIntegration::AdaptiveSimpsonsMethod(double a, double b, int N, double accuracy,
                                                  const std::function<double(double)> &func,
                                                  bool verbose) {
    double h = (b - a) / N;

    double Si = 0;
    // For k even
    for(int k = 2; k <= (N-2); k+=2){
        Si += func(a + k * h);
    }
    Si *= 2;
    Si += func(a) + func(b);
    Si *= 1.0/3.0;

    double Ti = 0;
    // For k odd
    for(int k = 1; k <= (N-1); k+=2){
        Ti += func(a + k * h);
    }
    Ti *= 2.0/3.0;

    double InitialIntegral = h * (Si + 2.0 * Ti);
    double RefinedIntegral = InitialIntegral;

    double Tprev;
    double Sprev;
    double Error;
    // This is our initial guess - we now increase N and decrease h until we hit our target accuracy
    do{
        // Store the previous values
        InitialIntegral = RefinedIntegral;
        RefinedIntegral = InitialIntegral;
        Tprev = Ti;
        Sprev = Si;
        // Clear out our sum terms
        Ti = 0;

        // Refine the estimate

        N *= 2.0;
        h /= 2.0;

        for(int k = 1; k <= (N-1); k+=2){
            Ti += func(a + k * h);
        }
        Ti *= 2.0/3.0;
        Si = Sprev + Tprev;
        RefinedIntegral = h * (Si + 2.0 * Ti);

        Error = (1.0/15.0)*std::abs((RefinedIntegral - InitialIntegral));

        if(verbose){
            std::cout << "N = " << N << ", Error = " << Error << std::endl;
        }

    }while(accuracy < Error);

    return RefinedIntegral;
}

double NumericIntegration::GaussianQuadrature(double a, double b, const std::function<double(double)> &func){
    return 10;
}