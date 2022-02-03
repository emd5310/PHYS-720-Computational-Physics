#include "EigenFinder.h"

double EigenFinder::QRDecomp(Eigen::MatrixXd A, double accuracy){
    int N = A.rows(); // Assumes this is a square matrix

    Eigen::MatrixXd R(N, N);
    Eigen::MatrixXd Q(N, N);

    Eigen::MatrixXd V = Eigen::MatrixXd::Identity(N, N);

    // These are index exactly how you'd expect
    std::vector<Eigen::VectorXd> q_N; // Stores all our q vectors
    std::vector<Eigen::VectorXd> u_N; // Stores all the u vectors

    std::cout << "Initial A:\n" << A << std::endl;

    do{

        q_N.clear();
        u_N.clear();
        
        Eigen::VectorXd a_i = Eigen::VectorXd::Zero(N);
        Eigen::VectorXd u_i = Eigen::VectorXd::Zero(N);
        Eigen::VectorXd q_i = Eigen::VectorXd::Zero(N);
        Eigen::VectorXd RunningSum = Eigen::VectorXd::Zero(N);

        // For all the columns of A, we calculate the values for q and u
        for(int i = 0; i < N; i++){
            a_i = A.col(i);

            // Then the general formula for u and q
            RunningSum = Eigen::VectorXd::Zero(N);

            for(int j = 0; j < i; j++){
                RunningSum += (q_N[j].dot(a_i)) * q_N[j];
            }
            u_i = a_i - RunningSum;
            u_N.push_back(u_i);

            // Now calculate the current q
            q_i = u_i / u_i.norm();
            q_N.push_back(q_i);

            // Set the current column in q to this value
            Q.col(i) = q_i;
        }

        // For each row
        for(int row = 0; row < N; row++){
            // Set the diagonal term
            R(row,row) = u_N[row].norm();
            // Then set the rest of the values across the row, column by column
            for(int col = (row+1); col < N; col++){
                R(row, col) = q_N[row].dot(A.col(col));
            }
        }

        std::cout << "Q:\n " << Q << std::endl;
        std::cout << "R:\n " << R << std::endl;

        A = R * Q;
        V = V * Q;

        std::cout << "A:\n " << A << std::endl;

    }while(abs(A(2,0)) >= accuracy);

    std::cout << "Final A:\n " << A << std::endl;
    std::cout << "Final V:\n " << V << std::endl; 

    return 1.00;
}