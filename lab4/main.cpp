#include "header.h"
#define EPS 1e-6
int main() {
    cout << "##################### X - COS(X) = 0 #####################\n";
    methodOfIterations(EPS, 1);
    methodOfNewton(EPS, 1);
    methodOfDivisionByTwo(-1.0, 1.0, EPS, 1);

    cout << fixed << setprecision(10);
    cout << "##################### ДРУГАЯ ТОЧНОСТЬ #####################\n";
    methodOfIterations(EPS / 100, 1);
    methodOfNewton(EPS / 100, 1);
    methodOfDivisionByTwo(-1.0, 1.0, EPS / 100, 1);

    cout << "##################### X - 10COS(X) = 0 #####################\n";
    methodOfIterations(EPS, 10);
    methodOfNewton(EPS, 10);
    methodOfDivisionByTwo(0, 4, EPS, 10);

    return 0;
}