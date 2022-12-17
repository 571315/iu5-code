#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a;
    double s;
    
    while (true) {
        cin >> a;

        s = 1.0f;
        if (a >= 0) {
            for (int i = 2; i <= 8; i += 2) {
                s *= (i * i);
            }
            s -= a;
        } else {
            for (int i = 3; i <= 9; i += 3) {
                s *= (i - 2);
            }
        }

        cout << fixed << setprecision(3) << s << endl;
    }
    return 0;
}