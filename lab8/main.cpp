#include "header.h"

int main() {
    int n;
    cin >> n;
    bool printAsFixed;
    cout << "Type print style (1 -- fixed, 0 -- scientific)\n";
    cin >> printAsFixed;

    int precision;
    cout << "Type precision\n";
    cin >> precision;

    double** A = createMatrix(n);
    fillMatrix(A, n);
    cout << "Matrix A\n";
    printMatrix(A, n, n, printAsFixed, precision);
    freeMemory(A, n);

    double B[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            B[i][j] = i * 10 + j;
        }
    }

    double** C = new double*[10];
    for (int i = 0; i < 10; ++i) {
        C[i] = B[i];
    }
    cout << "Matrix B\n";
    printMatrix(C, 10, 10, 1, 0);

    cout << B << "  " << B[0] << "  " << B[2] << endl;
	cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
	cout << *(*(B+1)) << "  " << *B[1] << endl;
	cout << *(B[0]+1) << "  " << *(*B+1) << endl;
	cout << B[0][20] << "  " << *(B[0]+20) << "  " << *B[2] << endl;

    return 0;
}