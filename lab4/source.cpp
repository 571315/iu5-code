#include "header.h"

double f(double x, const int k) {
    return x - k * cos(x);
}

double getSign(double x) {
    if (x > 0) return 1;
    else if (x == 0) return 0;
    return -1;
}


void methodOfIterations(const double EPS, const int k) {
    double prevX = 0, currX = 0;

    currX = k * cos(currX);
    int numberOfIterations = 1;
    while (std::abs(prevX - currX) >= EPS && numberOfIterations++ < 4000000) {
        prevX = currX;
        currX = k * cos(currX);
    }
    cout << "Метод итераций x: " << currX << " кол-во итераций: " << numberOfIterations << endl;
}


void methodOfDivisionByTwo(const double xLeft,
                           const double xRight,
                           const double EPS,
                           const int k,
                           int numberOfIterations) {
    double middle = xLeft + (xRight - xLeft) / 2;

    if (std::abs(f(middle, k)) < EPS) {
        cout << "Метод половинного деления x: " << middle << " кол-во итераций: " << numberOfIterations << endl;
        return;
    }

    ++numberOfIterations;

    if (getSign(f(xLeft, k)) != getSign(f(middle, k)))
        methodOfDivisionByTwo(xLeft, middle, EPS, k, numberOfIterations);
    else 
        methodOfDivisionByTwo(middle, xRight, EPS, k, numberOfIterations);
}


void methodOfNewton(const double EPS, const int k) {
    double prevX = 0, x = 0;

    int numberOfIterations = 0;

    while (std::abs(prevX - x) >= EPS || (x == 0 && prevX == 0)) {
        ++numberOfIterations;
        prevX = x;
        x -= (x - k * cos(x)) / (k * sin(x) + 1);
    }

    cout << "Метод Ньютона x: " << x << " кол-во итераций: " << numberOfIterations << endl;
}
