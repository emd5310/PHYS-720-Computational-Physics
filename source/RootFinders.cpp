#include "RootFinders.h"


    // Take in a vector of initial guesses, find roots for all of them
    // Return in the same order as they are found
    std::vector<double> RootFinders::NewtonsMethod(const std::function<double(double)>& func,
                                                   const std::function<double(double)>& func_prime,
                                                   const std::vector<double>& guesses, double tolerance) {
        std::vector<double> results;
        results.reserve(guesses.size());

        double Deltax; // Declare here to avoid constant reallocations
        double x;
        // For each guess, find the root
        for(auto& guess : guesses){
            x = guess;
            do{
                Deltax = func(x) / func_prime(x);
                x = x - Deltax;
            }while(std::abs(Deltax) >= tolerance);
            results.push_back(x);
        }

        return results;
    }


    // Implements the bisection method
    std::vector<double> RootFinders::BisectionMethod(const std::function<double(double)>& func,
                                                     const std::vector<std::pair<double, double>>& guesses,
                                                     double tolerance){
        std::vector<double> results;
        results.reserve(guesses.size());

        double x1, x2, func_x1, xprime;
        // For each pair we want to search between
        for(auto& SearchRange : guesses){
            x1 = SearchRange.first;
            x2 = SearchRange.second;

            func_x1 = func(x1);

            // Check that this method will work, and if so, execute it
            if(std::signbit(func(x1)) != std::signbit(func(x2))){

                do{
                    xprime = (1.0/2.0) * (x1 + x2);

                    if(std::signbit(func(xprime)) == std::signbit(func_x1)){
                        x1 = xprime;
                    }
                    else{
                        x2 = xprime;
                    }

                }while(abs(x1 - x2) >= tolerance);

            }
            results.push_back((1.0/2.0) * (x1 + x2));
        }

        return results;
    }

