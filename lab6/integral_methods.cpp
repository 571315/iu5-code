#include "integral_methods.h"

double f1(double x) { return x; }
double f2(double x) { return sin(22 * x); }

double f3(double x) { return x * x * x * x; }

double f4(double x) { return atan(x); }


double intRect(TPF f, double a, double b, const double EPS, int& n) {
    n = 2;

    double s0 = 0,
           s1 = 0,
           dx = 0;

    do {
        s0 = s1;
        s1 = 0;
        dx = (b - a) / n;
        for (int i = 0; i < n; ++i)
            s1 += f(a + dx * (i + 0.5));
        s1 *= dx;
        n *= 2;
    } while (fabs(s0 - s1) > EPS);

    return s1;
}

double intTrap(TPF f, double a, double b, const double EPS, int& n) {
    n = 2;
    double s0 = 0, dx = (b - a);
    double s1 = f(a + dx) + f(a + dx) * dx * 0.5;

    while (fabs(s0 - s1) > EPS) {
        s0 = s1;
        s1 = 0;
        n *= 2;
        dx = (b - a) / n;
        for (int i = 0; i < n; ++i)
            s1 += f(a + i * dx) + f(a + i * dx + dx);
        s1 *= dx * 0.5;
    }
    return s1;
}