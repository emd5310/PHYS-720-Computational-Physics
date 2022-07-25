#include "main.h"

double ProbOneFunc(double x){
    return std::pow(x, 4) - 2 * x + 1;
}

double ProblemOne(){
    double TenSlices = NumericIntegration::TrapezoidMethod(0, 2, 10, ProbOneFunc);
    double TwentySlices = NumericIntegration::TrapezoidMethod(0, 2, 20, ProbOneFunc);
    double Error = abs((1.0/3.0) * (TwentySlices - TenSlices));

    std::cout << "Twenty Slices: " << TwentySlices << " Err: " << Error << std::endl;
    // I get a value of 4.4266, with an error of 0.0266. The actual result is 4.4, so our solution is pretty good,
    // but the errors introduced by the trapezoids not quite fitting the actual curve throws our result off.
    // If we were to use more N...
    std::cout << "Four Hundred Slices: " << NumericIntegration::TrapezoidMethod(0, 2, 400, ProbOneFunc) << std::endl;
    // We get 4.40007 - much closer, since the trapezoids are much smaller, and can fit the curve better.
    return TwentySlices;
}

double ProbTwoFunc(double x){
    // Returns sin^2(sqrt(100x))
    return std::pow(std::sin(std::sqrt(100 * x)),2);
}

double ProblemTwo(){
    double epsilon = 1e-6;
    double result = NumericIntegration::AdaptiveSimpsonsMethod(0, 1, 2, epsilon, ProbTwoFunc, true);
    std::cout << "Final Result: " << result << std::endl;
    return result;
}

/**
 * Calls the various functions that execute my own tests or homework problems
 */
int main(int argc, char *argv[]){
    print("~~~ PHYS-720 : Computational Methods for Physics ~~~");
//    tests::AllTests();
    tests::AdaptiveIntegrationTest();
    tests::ThreadedAdaptiveSimpsonTest();

    return 0;
}