#include "ThreadedIntegration.h"

double ThreadedIntegration::ThreadedSimpsonsMethod(int threads, double a, double b, int N,
                                                   const std::function<double(double)> &func){
    // Break the range apart for each thread
    double result = 0;
    double *sum = &result;
    double stepSize = (b - a) / threads;
    int partialN = N / threads;
    double newa = a + stepSize;

    // Threaded stuff
    std::mutex sumlock;
    std::vector<std::thread> running;
    running.reserve(threads);

    for(int i = 0; i < threads; i++){
        running.emplace_back(std::ref(ThreadedIntegration::SimpsonsMethod), sum, std::ref(sumlock), a, newa, partialN, std::ref(func));
        a += stepSize;
        newa += stepSize;
    }
    for(auto &thread : running){
        thread.join();
    }
    return result;
}

double ThreadedIntegration::ThreadedAdaptiveMethod(int threads, double a, double b, int N, double accuracy,
                                                   const std::function<double(double)> &func, bool verbose) {
    double result = 0;
    double *sum = &result;
    double stepSize = (b - a) / threads;
    double newa = a + stepSize;

    // Threaded stuff
    std::mutex sumlock;
    std::vector<std::thread> running;
    running.reserve(threads);

    // Generate each thread, constructing it right inside of the vector
    for(int i = 0; i < threads; i++){
        running.emplace_back(std::ref(ThreadedIntegration::AdaptiveSimpsonsMethod), sum, std::ref(sumlock), a,
                             newa, N, accuracy, std::ref(func), verbose);
        a += stepSize;
        newa += stepSize;
    }
    // Make sure we wait for all the threads to complete their share of the calculation
    for(auto &thread : running){
        thread.join();
    }

    return result;
}

void ThreadedIntegration::SimpsonsMethod(double *sum, std::mutex &sumlock, double a, double b, int N,
                                         const std::function<double(double)>& func){
    double h = (b - a) / N;
    double EndPoints = func(a) + func(b);

    double OddRunningSum = 0;
    for(int k = 1; k <= (N-1); k+=2){
        OddRunningSum += func(a + k * h);
    }

    double EvenRunningSum = 0;
    for(int k = 2; k <= (N-2); k+=2){
        EvenRunningSum += func(a + k * h);
    }

    sumlock.lock();
    *sum += (1.0/3.0) * h * (EndPoints + 4 * OddRunningSum + 2 * EvenRunningSum);
    sumlock.unlock();
}

void ThreadedIntegration::AdaptiveSimpsonsMethod(double *sum, std::mutex &sumlock, double a, double b, int N,
                                                 double accuracy, const std::function<double(double)> &func,
                                                  bool verbose) {
    double h = (b - a) / N;

    double Si = 0;
    // For k even
    for(int k = 2; k <= (N-2); k+=2){
        Si += func(a + k * h);
    }
    Si *= 2;
    Si += func(a) + func(b);
    Si *= 1.0/3.0;

    double Ti = 0;
    // For k odd
    for(int k = 1; k <= (N-1); k+=2){
        Ti += func(a + k * h);
    }
    Ti *= 2.0/3.0;

    double InitialIntegral = h * (Si + 2.0 * Ti);
    double RefinedIntegral = InitialIntegral;

    double Tprev;
    double Sprev;
    double Error;
    // This is our initial guess - we now increase N and decrease h until we hit our target accuracy
    do{
        // Store the previous values
        InitialIntegral = RefinedIntegral;
        RefinedIntegral = InitialIntegral;
        Tprev = Ti;
        Sprev = Si;
        // Clear out our sum terms
        Ti = 0;

        // Refine the estimate

        N *= 2.0;
        h /= 2.0;

        for(int k = 1; k <= (N-1); k+=2){
            Ti += func(a + k * h);
        }
        Ti *= 2.0/3.0;
        Si = Sprev + Tprev;
        RefinedIntegral = h * (Si + 2.0 * Ti);

        Error = (1.0/15.0)*std::abs((RefinedIntegral - InitialIntegral));

        if(verbose){
            std::cout << "N = " << N << ", Error = " << Error << std::endl;
        }

    }while(accuracy < Error);
    sumlock.lock();
    *sum += RefinedIntegral;
    sumlock.unlock();
}


