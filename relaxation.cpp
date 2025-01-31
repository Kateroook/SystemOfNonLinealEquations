#include "Functions.h"

Vector relaxation(const Vector& x, const Matrix& C) {
    Vector Fx = F(x);
    Vector result = x;

    printVector(Fx, "Fx");

    Vector delta = multiplyMatrixVector(C, Fx);
    for (size_t i = 0; i < x.size(); ++i) {
        cout << "x[" << i+1 << "] = " << result[i] << " + " << delta[i] << " = ";
        result[i] += delta[i];
        cout << result[i] << endl;
    }
    return result;
}

void iterativeRelaxation(Vector x, const Matrix& C, double epsilon, size_t maxIterations) {
    std::cout << "Relaxation method\n";
    std::cout << "Initial approximation: (" << x[0] << ", " << x[1] << ")\n";
    std::cout << "Precision: " << epsilon << "\n\n";

    printMatrix(C, "C");

    for (size_t iteration = 0; iteration < maxIterations; ++iteration) {
        Vector nextX = relaxation(x, C);
        double diff = returnValueOfStoppingCondition(x, nextX);
        std::cout << "Iteration " << iteration + 1 << ": x = (" << nextX[0] << ", " << nextX[1] << "), ||x(k+1) - x(k)|| = ";
        printStoppingCondition(x, nextX, epsilon);
        std::cout << std::endl;

        if (diff <= epsilon) {
            std::cout << "Reached precision: ||x(k+1) - x(k)|| <= epsilon (" << diff << " <= " << epsilon << ")\n";
            printSolution(x, 'x', "Solution");
            return;
        }
        else {
            std::cout << "Reached precision: ||x(k+1) - x(k)|| > epsilon (" << diff << " > " << epsilon << ")\n";
                x = nextX;
        cout << endl << endl;
        }
    }

    std::cout << "Reached max quantity of iterations.\n";
}