#include <cmath>

typedef double (*TPF)(double);
typedef double (*methodPtr)(TPF, double, double, const double, int&);

double intRect(TPF f, double a, double b, const double EPS, int& n);
double intTrap(TPF f, double a, double b, const double EPS, int& n);

double f1(double x);
double f2(double x);
double f3(double x);
double f4(double x);