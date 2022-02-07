#ifndef EIGEN_FINDER_H
#define EIGEN_FINDER_H

#include <cmath>
#include <iostream>
#include <vector>

#include <Eigen/Core>

namespace EigenFinder{
    /**
     * Performs QR Decop to find eigenvectors and eigenvalues
     * @param A Real, square matrix
     * @param accuracy Desired accuracy for the off-diagonal terms
     * @return A's eigenvalues
     */
    std::vector<double> QRDecomp(Eigen::MatrixXd A, double accuracy);
}

#endif