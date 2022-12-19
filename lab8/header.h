#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double factorial(int n);

void freeMemory(double** matrix, int n);
double** createMatrix(int n);
void fillMatrix(double** matrix, int n);
int getConsoleWidth();
void printMatrix(double** matrix, int n, int m, bool printAsFixed);

