#include "Functions.h"

Vector F(const Vector& x) {
    return {
//        pow(x[0],2) + pow(x[1],2) -4,
//        x[0] - cos(x[1])
      pow(x[0],2) + pow(x[1],2) -27,
      pow(x[0]+1,2) - 2*x[1] - 3
    };
}

Matrix jacobi(const Vector& x) {
    return {
//        {2-0.5 * cos(x[0]/2 - x[1]/2), 0.5 * cos(x[0]/2 - x[1]/2)},
//        {0.5 * sin(x[0]/2 + x[1]/2), 2 + 0.5 * sin(x[0]/2 + x[1]/2)}
      {2*x[0], 2*x[1]},
      {2*(x[0]+1), -2}
    };
}

Vector multiplyMatrixVector(const Matrix& C, const Vector& Fx) {
    Vector result(Fx.size(), 0.0);
    for (size_t i = 0; i < C.size(); ++i) {
        for (size_t j = 0; j < C[i].size(); ++j) {
            result[i] += C[i][j] * Fx[j];
        }
    }
    return result;
}

Matrix inverse(const Matrix& J) {
    double det = J[0][0] * J[1][1] - J[0][1] * J[1][0];
    if (std::fabs(det) == 1e-12) {
        throw std::runtime_error("Matrix is degenerate");
    }
    return {
                { J[1][1] / det, -J[0][1] / det },
                {-J[1][0] / det,  J[0][0] / det }
    };
}


double returnValueOfStoppingCondition(const Vector& x, const Vector& nextX) {
    double max_x = 0.0;
    for (size_t i = 0; i < x.size(); ++i) {
        max_x = max(max_x, fabs(nextX[i] - x[i]));
    }
    return max_x;
}

void printStoppingCondition(const Vector& x, const Vector& nextX, double epsilon) {
    double max_x = 0.0;
    cout << "||(";
    for (size_t i = 0; i < x.size(); ++i) {
        max_x = max(max_x, fabs(nextX[i] - x[i]));
        cout << fabs(nextX[i] - x[i]) << "; ";
    }
    cout << ")|| = " << max_x;
}

void printSolution(const vector<double> &vec, const char& symbol, const string &name) {
    cout << name << "= \n";
    for (int i = 0; i < vec.size(); i++) {
        cout <<  symbol << i + 1 << " = " << vec[i] << "; ";
    }
    cout << endl;
}

void printMatrix(const Matrix &mat, const string &name) {
    cout << name << " =\n";
    for (const auto &row : mat) {
        for (double val : row) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const vector<double>& vec, const string &name) {
    cout << name << "= \n";
    for (double val : vec) {
        cout << setw(10) << val << " ";
    }
    cout << endl;
}