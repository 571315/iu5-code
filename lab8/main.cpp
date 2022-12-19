#include "header.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    bool printAsFixed;
    cout << "Введите стиль вывода (1 -- фиксированный, 0 -- научный)\n";
    cin >> printAsFixed;

    double** A = createMatrix(n);
    fillMatrix(A, n);
    cout << "Матрица A\n";
    printMatrix(A, n, n, printAsFixed);
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
    cout << "Матрица B\n";
    printMatrix(C, 10, 10, printAsFixed);

    cout << B << "  " << B[0] << "  " << B[2] << endl;
	cout << B[0][0] << "  " << **B << "  " << *B[0] << endl;
	cout << *(*(B+1)) << "  " << *B[1] << endl;
	cout << *(B[0]+1) << "  " << *(*B+1) << endl;
	cout << B[0][20] << "  " << *(B[0]+20) << "  " << *B[2] << endl;

    return 0;
}