#include "LinearSystems.h"

Eigen::VectorXd LinearSystems::GaussianElimination(Eigen::MatrixXd A, Eigen::VectorXd v){

    int N = v.size();
    
    for(int m = 0; m < N; m++){
        // Dividing the mth row by the mth element of that row, likewise for v
        double divisor = A(m, m);
        A.row(m) /= divisor;
        v(m) /= divisor;

        for(int n = (m+1); n < N; n++){
            // Subtracting the nth row by the mth element of that row times itself
            double factor = A(n, m);
            A.row(n) -= factor * A.row(m);
            v(n) -= factor * v(m);
        }
    }

    // Now carry out backsub to get the solutions
    return LinearSystems::BackSubstitution(A, v);
}

Eigen::VectorXd LinearSystems::BackSubstitution(Eigen::MatrixXd A, Eigen::VectorXd v){
    int N = v.size();
    Eigen::VectorXd solutions(N);

    for(int m = (N-1); m > -1; m--){
        solutions(m) = v(m);
        for(int n = (m+1); n < N; n++){
            solutions(m) -= A(m, n) * solutions(n);
        }
    }

    return solutions;
}

Eigen::VectorXd LinearSystems::LUDecomp(Eigen::MatrixXd A, Eigen::VectorXd v){
    int N = v.size();
    Eigen::VectorXd solutions(N); // Vector to store our solutions in
    Eigen::MatrixXd OriginalMatrix = A; // Copy of the original matrix for later
    std::vector<Eigen::MatrixXd> Lm; // Vector of matrices index according to L
    
    double factor;
    double divisor;
    for(int m = 0; m < N; m++){
        // Store these values for insertion into Li
        // They will be overwitten by the process of GE otherwise
        Eigen::VectorXd LiCol= A.col(m);

        // Dividing the mth row by the mth element of that row, likewise for v
        divisor = A(m, m);
        A.row(m) /= divisor;
        v(m) /= divisor;

        for(int n = (m+1); n < N; n++){
            // Subtracting the nth row by the mth element of that row times itself
            factor = A(n, m);
            A.row(n) -= factor * A.row(m);
            v(n) -= factor * v(m);
        }

        // Gaussian Elimination ends here- we now construct the Li matrix

        // Construct the ith matrix
        Eigen::MatrixXd Li = Eigen::MatrixXd::Identity(N, N);
        Li.col(m) = -1.0 * LiCol;
        // Modify the diagonals
        for(int i = 0; i<N;i++){
            Li(i,i) = divisor;
        }
        // Zero upper terms
        for(int i = 0; i<N; i++){
            for(int j = i+1; j<N; j++){
                Li(i,j) = 0.0;
            }
        }
        // Set the 1 on the diagonal
        Li(m,m) = 1;

        Lm.push_back((1.0/divisor) * Li);
    }

    // Start with the N-1th matrix, then multiply in succession to get the upper-triangular matrix
    Eigen::MatrixXd result = Lm[N-1];
    for(int i = N-2; i >= 0; i--){
        std::cout << i << std::endl;
        result *= Lm[i];
    }
    result *= OriginalMatrix;

    return solutions;
}