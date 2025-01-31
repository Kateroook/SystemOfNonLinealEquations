#include "Functions.h"

Vector newtonModified(const Vector& x, const Matrix& A) {
    Vector Fx = F(x);
    Vector result = x;
    Matrix A_inv = inverse(A);
    Vector delta = multiplyMatrixVector(A_inv, Fx);

    printVector(Fx, "Fx^k");
    printVector(delta, "A^-1 * Fx^k");

    for (size_t i = 0; i < x.size(); ++i) {
        cout << "x[" << i+1 << "] = " << result[i] << " - " << delta[i] << " = ";
        result[i] -= delta[i];
        cout << result[i] << endl;
    }
    return result;
}

void iterativeNewtonModified(Vector x, const Matrix& A, double epsilon, size_t maxIterations) {
    cout << "Newton's Modified method\n";
    cout << "Initial approximation: (" << x[0] << ", " << x[1] << ")\n";
    cout << "Precision: " << epsilon << "\n\n";
    Matrix A_inv = inverse(A);
    printMatrix(A_inv, "A^-1");

    for (size_t iteration = 0; iteration < maxIterations; ++iteration) {
        Vector nextX = newtonModified(x, A);
        double diff = returnValueOfStoppingCondition(x, nextX);
        cout << "Iteration " << iteration + 1 << ": x = (" << nextX[0] << ", " << nextX[1] << "), ||x(k+1) - x(k)|| = ";
        printStoppingCondition(x, nextX, epsilon);
        cout << std::endl;

        if (diff <= epsilon) {
            cout << "Reached precision: ||x(k+1) - x(k)|| <= epsilon (" << diff << " <= " << epsilon << ")\n";
            printSolution(x,'x', "Solution");
            return;
        }else {
            cout << "Reached precision: ||x(k+1) - x(k)|| > epsilon (" << diff << " > " << epsilon << ")\n";
            x = nextX;
            cout << endl << endl;
        }
    }
    cout << "Reached max quantity of iterations.\n";
}