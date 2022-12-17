#include <iostream>

using namespace std;

double getCoefficient(double x, double n) {
    return -(x * x) / (4 * n * n + 6 * n + 2);
}

int main() {
    double x, s, currentMember;
    int numberOfIterations;

    cout << "Введите x\n";
    cin >> x;

    while (true) {
        cout << "Введите n\n";
        cin >> numberOfIterations;

        // First, sum first member of the row (just x) to S
        s = 1;
        currentMember = 1;

        // Second, let's calc new members and them to s
        for (int i = 0; i < numberOfIterations; ++i) { // i -- Номер последнего вычисленного слагаемого (с нуля)
            currentMember = getCoefficient(x, i) * currentMember;
            s += currentMember;
            if (i == 1 || i == 3 || i == 8) {
                cout << "Промежуточное значение i: " << i + 2 << " y: " << s << endl;
            }
        }
        cout << "y = " << s << endl;
    }
    return 0;
}
