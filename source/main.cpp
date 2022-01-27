#include "main.h"

void IntegrationTest(){
    double test_area = NumericIntegration::TrapezoidMethod(0, 100, 1000, SimpleQuadratic);
    std::cout << "Trap Method: " << std::endl;
    std::cout << test_area << std::endl;

    test_area = NumericIntegration::SimpsonsMethod(0, 100, 100, SimpleQuadratic);
    std::cout << "Simp Method: " << std::endl;
    std::cout << test_area << std::endl;
    return;
}

void GaussianElimTest(){
    Eigen::MatrixXd MatTest(3, 3);
    Eigen::VectorXd VecTest(3);

    MatTest << 2, 1, 1,
               1, 3, 1,
               1, 1, 4;

    VecTest << 1, 2, 3;

    std::cout << LinearSystems::GaussianElimination(MatTest, VecTest) << std::endl;
    return;
}

void LUDecompTest(){
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
    LUDecompTest();

    return 0;
}