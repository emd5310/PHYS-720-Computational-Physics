#ifndef COMPPHYS_THREADEDINTEGRATION_H
#define COMPPHYS_THREADEDINTEGRATION_H

#include <cmath>
#include <functional>
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

namespace ThreadedIntegration{

    /**
     * Breaks an integral apart, evenly amongst threads
     * @param threads to use
     * @param a Start of total integration range
     * @param b End of total integration range
     * @param N Number of slices to start with for each range
     * @param func To integrate
     * @return
     */
    double ThreadedSimpsonsMethod(int threads, double a, double b, int N, const std::function<double(double)> &func);
    double ThreadedAdaptiveMethod(int threads, double a, double b, int N, double accuracy,
                                  const std::function<double(double)> &func, bool verbose=false);

    /**
     * Impelements the numerical method allowing for multithreading
     * @param sum Pointer to the result of the total integral
     * @param sumlock Mutex for sum
     * @param a Start of this range portion
     * @param b End of this range portion
     * @param N Number of slices to start the approximation with
     * @param func To integrate
     */
    void SimpsonsMethod(double *sum, std::mutex &sumlock, double a, double b, int N,
                        const std::function<double(double)>& func);
    // Same as above, but dynamically changes N and h (Note that N is for all threads)
    void AdaptiveSimpsonsMethod(double *sum, std::mutex &sumlock, double a, double b, int N, double accuracy,
                                  const std::function<double(double)> &func, bool verbose= false);
}


#endif //COMPPHYS_THREADEDINTEGRATION_H
