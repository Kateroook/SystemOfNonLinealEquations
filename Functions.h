#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

using Vector = vector<double>;
using Matrix = vector<vector<double>>;

Vector F(const Vector& x);
Matrix jacobi(const Vector& x);

Vector multiplyMatrixVector(const Matrix& C, const Vector& Fx) ;
Matrix inverse(const Matrix& J);

Vector relaxation(const Vector& x, const Matrix& C);
void iterativeRelaxation(Vector x, const Matrix& C, double epsilon, size_t maxIterations);

Vector newtonModified(const Vector& x, const Matrix& A);
void iterativeNewtonModified(Vector x, const Matrix& A, double epsilon, size_t maxIterations);

void printStoppingCondition(const Vector& x, const Vector& nextX, double epsilon);

double returnValueOfStoppingCondition(const Vector& x, const Vector& nextX);

void printSolution(const vector<double> &vec, const char& symbol, const string &name);
void printMatrix(const Matrix &mat, const string &name);
void printVector(const vector<double>& vec, const string &name);
#endif //FUNCTIONS_H
