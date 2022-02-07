#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include <cmath>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

#include <Eigen/Core>

namespace LinearSystems{

    /**
     * Carries out backsubstitution for...
     * @param A Real, square coefficient matrix
     * @param v 'Solution' vector
     * @return the vector containing the solutions to this system
     */
    Eigen::VectorXd BackSubstitution(Eigen::MatrixXd A, Eigen::VectorXd v);

    /**
     * Performs Gaussian Elimination
     * @param A Real, square coefficient matrix
     * @param v 'Solution' vector
     * @return the vector containing the solutions to this system
     */
    Eigen::VectorXd GaussianElimination(Eigen::MatrixXd A, Eigen::VectorXd v);
    /**
     * Performs Gaussian Elimination using Partial Pivoting
     * @param A Real, square coefficient matrix
     * @param v 'Solution' vector
     * @return the vector containing the solutions to this system
     */
    Eigen::VectorXd GaussianEliminationPP(Eigen::MatrixXd A, Eigen::VectorXd v);

    /**
     * Performs LU-Decomposition
     * @param A Real, square coefficient matrix
     * @param v 'Solution' vector
     * @return the vector containing the solutions to this system
     */
    Eigen::VectorXd LUDecomp(Eigen::MatrixXd A, Eigen::VectorXd v);

}

#endif