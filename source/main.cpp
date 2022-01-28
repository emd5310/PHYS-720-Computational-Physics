#include "main.h"

void AdaptiveIntegrationTest(){
    std::cout << "Setting terminal precision to 12 digits!" << std::setprecision (12) << std::endl;
    double test_area = NumericIntegration::AdaptiveTrapezoidMethod(0, 7, 1, 0.0001, WeirdPoly);
    std::cout << "Adaptive Trapezoidal Method: " << test_area << std::endl;

    test_area = NumericIntegration::AdaptiveSimpsonsMethod(0, 7, 1, 0.0001, WeirdPoly);
    std::cout << "Adaptive Trapezoidal Method: " << test_area << std::endl;

    return;
}


void IntegrationTest(){
    double TestArea = NumericIntegration::TrapezoidMethod(0, 100, 1000, SimpleQuadratic);
    std::cout << "Trapezoidal Method: " << TestArea << std::endl;

    TestArea = NumericIntegration::SimpsonsMethod(0, 100, 100, SimpleQuadratic);
    std::cout << "Simpsons Method: " << TestArea << std::endl;
    return;
}


void GaussianElimTest(){
    std::cout << "\nGaussian Elimination Test:\n" << std::endl;
    Eigen::MatrixXd MatTest(4, 4);
    Eigen::VectorXd VecTest(4);

    MatTest << 2, 1, 4, 1,
               3, 4, -1, -1,
               1, -4, -1, -1,
               2, -2, 1, 3;

    VecTest << -4, 3, 9, 7;

    std::cout << LinearSystems::GaussianElimination(MatTest, VecTest) << std::endl;
    return;
}

void LUDecompTest(){
    std::cout << "\nLU Decomposition Test:\n" << std::endl;
    Eigen::MatrixXd MatTest(4, 4);
    Eigen::VectorXd VecTest(4);

    MatTest << 2, 1, 4, 1,
               3, 4, -1, -1,
               1, -4, -1, -1,
               2, -2, 1, 3;

    VecTest << -4, 3, 9, 7;

    std::cout << LinearSystems::LUDecomp(MatTest, VecTest) << std::endl;
    return;
}


int main(int argc, char *argv[]){
    print("~~~ PHYS-720 : Computational Methods for Physics ~~~\n");

    // IntegrationTest();
    // GaussianElimTest();
    // LUDecompTest();
    // AdaptiveIntegrationTest();

    return 0;
}