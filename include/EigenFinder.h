#ifndef EIGEN_FINDER_H
#define EIGEN_FINDER_H

#include <cmath>
#include <iostream>
#include <vector>

#include <Eigen/Core>

namespace EigenFinder{
    double QRDecomp(Eigen::MatrixXd A, double accuracy);

}

#endif