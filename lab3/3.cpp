#include <iostream>
#include <cmath>
#include <iomanip>

#define Y(x) sin(x)  // Define makes Y(x) the same as sin(x). It just replaces all Y(x) to sin(x)
#define EPS 1e-6  // Replaces all EPS with 1e-6

using namespace std;


double getCoefficient(double n, double x) {
    double chislitel = -x * x;
    double znamenatel = (4 * n * n) + (2 * n);
    return chislitel / znamenatel;
}

int main () {
    cout << "  x      Y(x)      S(x)         N\n";
    double s, prevMember;
    int n;
    for (double x = 0.0; x <= 1.0; x += 0.2) {
        // First, sum first member of the row (just x) to S
        s = x;
        n = 1;
        prevMember = x;

        // Second, let's calc new members and them to s till the diff is bigger than EPS
        while (abs((getCoefficient(n, x) - 1) * prevMember) > EPS) {
            prevMember =  getCoefficient(n, x) * prevMember;
            s += prevMember;
            n++;
        }
        cout << fixed << setprecision(1) << setw(3) << x << setw(10) << setprecision(7) << Y(x) << setw(10) << s << setw(10) << n << endl;
    }

    return 0;
}