#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double getSign(double x);

double f (double x, const int k);

void methodOfDivisionByTwo(const double xLeft,
                           const double xRight,
                           const double EPS,
                           const int k,
                           int numberOfIterations = 0);

void methodOfIterations(const double EPS, const int k);

void methodOfNewton(const double EPS, const int k);
