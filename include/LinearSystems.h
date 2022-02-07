#ifndef GAUSSIAN_ELIMINATION_H
#define GAUSSIAN_ELIMINATION_H

#include <cmath>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>

#include <Eigen/Core>

namespace LinearSystems{

    // Back-subs from bottom-top to solve a Gaussian Elim'd system
    Eigen::VectorXd BackSubstitution(Eigen::MatrixXd A, Eigen::VectorXd v);

    /**
     * Carries out the process of solving a system of equations in the form of a matrix of coefficients, A
     * and a vector containing the solution coefficients, v
     */
    Eigen::VectorXd GaussianElimination(Eigen::MatrixXd A, Eigen::VectorXd v);
    // Same as above but using Partial Pivoting
    Eigen::VectorXd GaussianEliminationPP(Eigen::MatrixXd A, Eigen::VectorXd v);

    /**
     * Solves a system of equations using LU Decomposition, where the coefficient matrix A is used to generate 
     * the L_n matrices for use on multiple v's
     */
    Eigen::VectorXd LUDecomp(Eigen::MatrixXd A, Eigen::VectorXd v);

}

#endif