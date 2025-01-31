#include <iostream>

#include "Functions.h"

int main() {
    size_t n = 2;
    Vector x = {-3, 1};
    Matrix C = {
        {0.15, 0.0},
        {0.0, 0.15}
    };
    Matrix A = jacobi(x);
    printMatrix(A, "Jacobi at x0");

    double epsilon = 0.0001;
    size_t maxIterations = 1000;

    iterativeRelaxation(x, C, epsilon, maxIterations);
    //iterativeNewtonModified(x, A, epsilon, maxIterations);

    return 0;
}
