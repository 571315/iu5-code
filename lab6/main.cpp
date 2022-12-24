#include "integral_methods.h"
#include "table_print.h"

int main() {
    const double precisions[] = { 0.01, 0.001, 0.0001, 0.00001, 0.000001 };
    const char* funcNames[] = { " y = x  ", "y = sin(22x)", "y = x^4 ", "y = arctg(x)"};
    const TPF functions[] = { f1, f2, f3, f4 };

    const methodPtr methods[] = { intRect, intTrap };
    const char* methodNames[] = { "Rect method", "Trap method" }; 

    double a = 0, b = 4;  // Границы интегрирования
    int n;
    double s;

    const double exactIntegValues[] = { (b * b - a * a) / 2.0, 
                                        (cos(a * 22.0) - cos(b * 22.0)) / 22.0,
                                        (b * b * b * b * b - a * a * a * a * a) / 5,
                                         b * atan(b) - a*atan(a) - (log(b*b+1) - log(a*a+1)) / 2 };
    I_print printData[5];
    methodPtr usedMethod;

    for (int methodIndex = 0; methodIndex < 2; ++methodIndex) {
        cout << methodNames[methodIndex] << '\n';
        for (int i = 0; i < 5; ++i) {  // precision
            cout << "PRECISION: " << precisions[i] << '\n';
            for (int j = 0; j < 4; ++j) {  // function
                usedMethod = methods[methodIndex];
                s = usedMethod(functions[j], a, b, precisions[i], n);
                printData[j].name = funcNames[j];
                printData[j].i_sum = s;
                printData[j].i_toch = exactIntegValues[j];
                printData[j].n = n;
            }

            PrintTabl(printData, 4);
        }
    }
    cin.get();
    return 0;
}