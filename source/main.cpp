#include "main.h"

void GaussianElimination(){
    print("\nGaussian Elimination:");

    Eigen::MatrixXd Coefficients(4, 4);
    Coefficients << 4, -1, -1, -1,
               -1, 3, 0, -1,
               -1, 0, 3, -1,
               -1, -1, -1, 4;

    Eigen::VectorXd v(4);
    v << 5, 0, 5, 0;

    std::cout << LinearSystems::GaussianElimination(Coefficients, v) << std::endl;
}

void GaussianEliminationPP(){
    print("\nGaussian Elimination with Partial Pivoting");

    Eigen::MatrixXd Coefficients(4, 4);
    Eigen::VectorXd v(4);

    Coefficients << 2, 1, 4, 1,
            3, 4, -1, -1,
            1, -4, 1, 5,
            2, -2, 1, 3;

    v << -4, 3, 9, 7;

    std::cout << LinearSystems::GaussianEliminationPP(Coefficients, v) << std::endl;
}

void LUDecomp(){
    print("\nLU Decomposition:");

    Eigen::MatrixXd LUMatrix(4, 4);
    LUMatrix << 2, 1, 4, 1,
            3, 4, -1, -1,
            1, -4, 1, 5,
            2, -2, 1, 3;

    Eigen::VectorXd vec(4);
    vec << -4, 3, 9, 7;

    std::cout << LinearSystems::LUDecomp(LUMatrix, vec) << std::endl;
}

void QRAlgorithm(){
    print("\nEigenvalues: ");

    Eigen::MatrixXd QRMatrix(4, 4);
    QRMatrix << 1, 4, 8, 4,
        4, 2, 3, 7,
        8, 3, 6, 9,
        4, 7, 9, 2;

    for(auto value : EigenFinder::QRDecomp(QRMatrix, 0.0000001)){
        std::cout << value << std::endl;
    }
}

/**
 * Calls the various functions that execute my own tests or homework problems
 */
int main(int argc, char *argv[]){
    print("~~~ PHYS-720 : Computational Methods for Physics ~~~");

    // NewtonsMethod();
    // BisectionMethod();
    // IntegrationTest();
    // AdaptiveIntegrationTest();
    QRAlgorithm();
    LUDecomp();
    GaussianElimination();
    GaussianEliminationPP();

    return 0;
}