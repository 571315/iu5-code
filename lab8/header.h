#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

double factorial(int n);

void freeMemory(double** matrix, int n);
double** createMatrix(int n);
void fillMatrix(double** matrix, int n);
int getConsoleWidth();
void printMatrix(double** matrix, int n, int m, bool printAsFixed, int precision);

