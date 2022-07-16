#include "tests.h"

void tests::AllTests(){
    QRAlgorithm(); // THIS MUST RUN FIRST
    NewtonsMethod();
    BisectionMethod();
    IntegrationTest();
    AdaptiveIntegrationTest();
    GaussianElimination();
    GaussianEliminationPP();
    LUDecomp();
}

void tests::NewtonsMethod(){
    std::cout << "\nNewton's Method - Nonlinear Solutions: " << std::endl;

    std::vector<double> guesses{0.037, 0.171, 0.379, 0.623, 0.833, 0.967};
    double tolerance = 0.00000001;
    std::cout << std::setprecision(12) << std::endl;

    for(auto& value : RootFinders::NewtonsMethod(tests::Polynomial, tests::PolynomialPrime, guesses, tolerance)) {
        std::cout << value << std::endl;
    }
}

void tests::BisectionMethod(){
    std::cout << "\nBisection Method - Nonlinear Solutions: " << std::endl;

    std::vector<std::pair<double, double>> guesses{
            {0.028, 0.0434},
            {0.165, 0.174},
            {0.37, 0.39},
            {0.81, 0.84}};

    double tolerance = 1e-9;
    std::cout << std::setprecision(12) << std::endl;

    for(auto& value : RootFinders::BisectionMethod(tests::Polynomial, guesses, tolerance)) {
        std::cout << value << std::endl;
    }
}

void tests::AdaptiveIntegrationTest(){
    std::cout << "\nSetting terminal precision to 12 digits!" << std::setprecision (12) << std::endl;
    double test_area = NumericIntegration::AdaptiveTrapezoidMethod(0, 7, 1, 0.0001, tests::WeirdPoly);
    std::cout << "Adaptive Trapezoidal Method: " << test_area << std::endl;

    test_area = NumericIntegration::AdaptiveSimpsonsMethod(0, 7, 1, 0.0001, tests::WeirdPoly, false);
    std::cout << "Adaptive Simpsons Method: " << test_area << std::endl;
}

void tests::IntegrationTest(){
    double TestArea = NumericIntegration::TrapezoidMethod(0, 100, 1000, tests::SimpleQuadratic);
    std::cout << "\nTrapezoidal Method: " << TestArea << std::endl;

    TestArea = NumericIntegration::SimpsonsMethod(0, 100, 100, tests::SimpleQuadratic);
    std::cout << "Simpsons Method: " << TestArea << std::endl;
}

void tests::GaussianElimination(){
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

void tests::GaussianEliminationPP(){
    std::cout << "\nGaussian Elimination with Partial Pivoting" << std::endl;

    Eigen::MatrixXd Coefficients(4, 4);
    Eigen::VectorXd v(4);

    Coefficients << 2, 1, 4, 1,
            3, 4, -1, -1,
            1, -4, 1, 5,
            2, -2, 1, 3;

    v << -4, 3, 9, 7;

    std::cout << LinearSystems::GaussianEliminationPP(Coefficients, v) << std::endl;
}

void tests::LUDecomp(){
    std::cout << "\nLU Decomposition:"  << std::endl;

    Eigen::MatrixXd LUMatrix(4, 4);
    LUMatrix << 2, 1, 4, 1,
            3, 4, -1, -1,
            1, -4, 1, 5,
            2, -2, 1, 3;

    Eigen::VectorXd vec(4);
    vec << -4, 3, 9, 7;

    std::cout << LinearSystems::LUDecomp(LUMatrix, vec) << std::endl;
}

void tests::QRAlgorithm(){
    std::cout << "\nEigenvalues: "  << std::endl;

    Eigen::MatrixXd QRMatrix(4, 4);
    QRMatrix << 1, 4, 8, 4,
            4, 2, 3, 7,
            8, 3, 6, 9,
            4, 7, 9, 2;

    for(auto value : EigenFinder::QRDecomp(QRMatrix, 0.0000001)){
        std::cout << value << std::endl;
    }
}

void tests::CentralDifference(){
    std::cout << std::setprecision(12);
    for(double val : NumericDerivative::CentralDifference(0, 1, 1000, tests::SimpleQuadratic)){
        std::cout << val << "\n";
    }
}

double tests::SimpleQuadratic(double x){
    return std::pow(x, 2);
}

double tests::Polynomial(double x){
    return 924*std::pow(x,6) - 2772*std::pow(x,5) + 3150*std::pow(x,4) -
           1680*std::pow(x,3) + 420*std::pow(x,2) - 42*x + 1;
}

double tests::PolynomialPrime(double x){
    return 42*(132*std::pow(x,5) - 330*std::pow(x,4) + 300*std::pow(x,3) -
               120*std::pow(x,2) + 20*x -1);
}

double tests::WeirdPoly(double x){
    return 2.0 * std::pow(x, 3) + 5.0 * std::pow(x, 2) - 11.2 * x;
}



