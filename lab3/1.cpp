#include <iostream>

using namespace std;

int main() {
    int sum;
    int n, m;
    
    while (true) {
        cin >> n >> m;

        sum = 0;

        for (int i = 5; i <= n; i += 5) {
            if (i % m != 0) {
                sum += i;
            }
        }

        cout << sum << endl;
    }
    return 0;
}