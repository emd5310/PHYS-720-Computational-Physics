#include "main.h"

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

void GaussianElimination(){
    std::cout << "\nGaussian Elimination:" << std::endl;

    Eigen::MatrixXd Coefficients(4, 4);
    Coefficients << 4, -1, -1, -1,
               -1, 3, 0, -1,
               -1, 0, 3, -1,
               -1, -1, -1, 4;

    Eigen::VectorXd v(4);
    v << 5, 0, 5, 0;

    std::cout << LinearSystems::GaussianElimination(Coefficients, v) << std::endl;
}

void LUDecomp(){
    std::cout << "\nLU Decomposition:" << std::endl;

    Eigen::MatrixXd LUMatrix(4, 4);
    LUMatrix << 2, 1, 4, 1,
               3, 4, -1, -1,
               1, -4, -1, -1,
               2, -2, 1, 3;

    Eigen::VectorXd v(4);
    v << -4, 3, 9, 7;

    std::cout << LinearSystems::LUDecomp(LUMatrix, v) << std::endl;
}

void QRAlgorithm(){
    std::cout << "\nEigenvalues: " << std::endl;

    Eigen::MatrixXd QRMatrix(4, 4);
    QRMatrix << 1, 4, 8, 4,
        4, 2, 3, 7,
        8, 3, 6, 9,
        4, 7, 9, 2;

    for(auto value : EigenFinder::QRDecomp(QRMatrix, 0.0000001)){
        std::cout << value << std::endl;
    }
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

int main(int argc, char *argv[]){
    print("~~~ PHYS-720 : Computational Methods for Physics ~~~");

    // IntegrationTest();
    // AdaptiveIntegrationTest();
    // GaussianElimination();
    // QRAlgorithm();
    // LUDecomp();
    // NewtonsMethod();
    BisectionMethod();

    return 0;
}