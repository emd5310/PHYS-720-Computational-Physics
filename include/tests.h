#ifndef TESTS_H
#define TESTS_H

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
#include "Derivatives.h"
#include "EigenFinders.h"
#include "LinearSystems.h"
#include "Integration.h"
#include "Interpolation.h"
#include "RootFinders.h"
#include "ThreadedIntegration.h"

namespace tests{

    void AllTests();

    void NewtonsMethod();
    void BisectionMethod();
    void AdaptiveIntegrationTest();
    void IntegrationTest();
    void GaussianElimination();
    void GaussianEliminationPP();
    void LUDecomp();
    void QRAlgorithm();
    void CentralDifference();

    void ThreadedAdaptiveSimpsonTest();

    double SimpleQuadratic(double x);
    double Polynomial(double x);
    double PolynomialPrime(double x);
    double WeirdPoly(double x);

}
#endif
