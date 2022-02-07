#include "LinearSystems.h"

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

Eigen::VectorXd LinearSystems::LUDecomp(Eigen::MatrixXd A, Eigen::VectorXd v){
    int N = v.size();
    Eigen::VectorXd solutions(N); // Vector to store our solutions in
    Eigen::MatrixXd OriginalMatrix = A; // Copy of the original matrix for later
    Eigen::MatrixXd LInverse(N, N); // The L^-1 matrix we construct later
    std::vector<Eigen::MatrixXd> Lm; // Vector of matrices index according to L
    
    double factor;
    double divisor;
    for(int m = 0; m < N; m++){
        // Store these values for insertion into Li
        // They will be overwritten by the process of GE otherwise
        Eigen::VectorXd LCol= A.col(m);

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

        // ---- Gaussian Elimination steps end here ----
        // We now construct the L_i matrix 

        // Construct the ith matrix
        Eigen::MatrixXd L = Eigen::MatrixXd::Identity(N, N);
        L.col(m) = -1.0 * LCol; // Store this to make the L_i matrix
        LInverse.col(m) = LCol; // Store this to make the L^-1 matrix
        // Modify the diagonals
        for(int i = 0; i<N;i++){
            L(i,i) = divisor;
        }
        // Zero upper terms
        for(int i = 0; i<N; i++){
            for(int j = i+1; j<N; j++){
                L(i,j) = 0.0;
            }
        }
        // Set the 1 on the diagonal
        L(m,m) = 1;

        Lm.emplace_back((1.0/divisor) * L);
    }

    // Start with the N-1 matrix, then multiply in succession to get the upper-triangular matrix
    Eigen::MatrixXd U = Lm[N-1];
    for(int i = N-2; i >= 0; i--){
        U *= Lm[i];
    }
    U *= OriginalMatrix; // This is our complete U matrix

    // Zero upper terms of the L-1 matrix
    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            LInverse(i,j) = 0.0;
        }
    }

    std::cout << "LU Recovery:\n" << LInverse*U << "\n" << std::endl;

    // Double Back-sub to get the complete solution
    solutions = LinearSystems::BackSubstitution(U, LinearSystems::BackSubstitution(LInverse, v));

    return solutions;
}

Eigen::VectorXd LinearSystems::GaussianEliminationPP(Eigen::MatrixXd A, Eigen::VectorXd v){

    int N = v.size();

    for(int m = 0; m < N; m++){
        // As long as there is somewhere to pivot to...
        if(m + 1 < N){
            // Copy the current row and switch it with the last one
            Eigen::VectorXd CurrentRow = A.row(m); // Copy the current row
            double CurrentV = v(m);
            // Check for a valid lower row to switch with
            bool pivot = true;
            for(int j = m+1; j < N; j++){
                if(abs(A(j,m)) > A(m, m) && pivot) {
                    A.row(m) = A.row(j); // Swap the current row for the new one
                    A.row(j) = CurrentRow; // Then set the row we moved to the previous
                    // Likewise for the solution vector
                    v(m) = v(j);
                    v(j) = CurrentV;
                    pivot = false;
                }
            }
        }

        // Dividing the mth row by the mth element of that row, likewise for v
        double divisor = A(m,m);

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