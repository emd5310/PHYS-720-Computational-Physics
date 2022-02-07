#ifndef MAIN_H
#define MAIN_H

// Standard libraries
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

// 3rd Party
#include <Eigen/Core>
#include <Eigen/Eigenvalues> // For eigenvalues
#include <Eigen/LU> // For determinants

// Project-level
#include "EigenFinders.h"
#include "LinearSystems.h"
#include "Integration.h"
#include "Interpolation.h"
#include "RootFinders.h"

std::string print(std::string message){
    std::cout << message << std::endl;
    return message;
}

double SimpleQuadratic(double x){
    return std::pow(x, 2);
}

double Polynomial(double x){
    return 924*std::pow(x,6) - 2772*std::pow(x,5) + 3150*std::pow(x,4) -
            1680*std::pow(x,3) + 420*std::pow(x,2) - 42*x + 1;
}

double PolynomialPrime(double x){
    return 42*(132*std::pow(x,5) - 330*std::pow(x,4) + 300*std::pow(x,3) -
            120*std::pow(x,2) + 20*x -1);
}

double WeirdPoly(double x){
    return 2.0 * std::pow(x, 3) + 5.0 * std::pow(x, 2) - 11.2 * x;
}

void NewtonsMethod(){
    std::cout << "\nNonlinear Solutions: " << std::endl;

    std::vector<double> guesses{0.037, 0.171, 0.379, 0.623, 0.833, 0.967};
    double tolerance = 0.00000001;

    for(auto& value : RootFinders::NewtonsMethod(Polynomial, PolynomialPrime, guesses, tolerance)) {
        std::cout << value << std::endl;
    }
}

void BisectionMethod(){
    std::cout << "\nNonlinear Solutions: " << std::endl;

    std::vector<std::pair<double, double>> guesses{
            {0.028, 0.0434},
            {0.165, 0.174},
            {0.37, 0.39},
            {0.81, 0.84}};

    double tolerance = 1e-9;
    std::cout << std::setprecision(12) << std::endl;

    for(auto& value : RootFinders::BisectionMethod(Polynomial, guesses, tolerance)) {
        std::cout << value << std::endl;
    }
}

void AdaptiveIntegrationTest(){
    std::cout << "Setting terminal precision to 12 digits!" << std::setprecision (12) << std::endl;
    double test_area = NumericIntegration::AdaptiveTrapezoidMethod(0, 7, 1, 0.0001, WeirdPoly);
    std::cout << "Adaptive Trapezoidal Method: " << test_area << std::endl;

    test_area = NumericIntegration::AdaptiveSimpsonsMethod(0, 7, 1, 0.0001, WeirdPoly);
    std::cout << "Adaptive Simpsons Method: " << test_area << std::endl;
}

void IntegrationTest(){
    double TestArea = NumericIntegration::TrapezoidMethod(0, 100, 1000, SimpleQuadratic);
    std::cout << "Trapezoidal Method: " << TestArea << std::endl;

    TestArea = NumericIntegration::SimpsonsMethod(0, 100, 100, SimpleQuadratic);
    std::cout << "Simpsons Method: " << TestArea << std::endl;
}



#endif