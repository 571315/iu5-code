#include "header.h"
#include <ios>

void freeMemory(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


double factorial(int n) {
    if (n < 2)
        return 1;
    return n * factorial(n - 1);
}

double** createMatrix(int n) {
    double** matrix = new double*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }
    return matrix;
}


void fillMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {  // Главная диагональ
                matrix[i][j] = 1;
                continue;
            }
            if (j > i) {  // Выше главной
                matrix[i][j] = pow(1 / factorial(j + 1), i + 1);
            } else {  // Ниже главной
                matrix[i][j] = pow(-1 / factorial(j + 1), i + 1);
            }
        }
    }
}

int getConsoleWidth() {
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

void printMatrix(double** matrix, int n, int m, bool printAsFixed) {
    int width = getConsoleWidth();

    int rowSize = printAsFixed? 12 : 16;
    int numOfPrintedColumns = 0;
    int maxColumnsOnLine = width / rowSize;
    while (numOfPrintedColumns < m) {
        for (int i = 0; i < n; ++i) {
            for (int j = numOfPrintedColumns; j < maxColumnsOnLine + numOfPrintedColumns; ++j) {
                if (j == m) 
                    break;

                if (printAsFixed) {
                    if (matrix[i][j] > 0 && matrix[i][j] < 10) 
                        cout << ' ';
                    cout << ' ' << fixed << setprecision(8) << matrix[i][j];
                } else {
                    if (matrix[i][j] < 0)
                        cout << "  " << scientific << setprecision(8) << matrix[i][j];
                    else 
                        cout << "   " << scientific << setprecision(8) << matrix[i][j];
                }
            }
            cout << endl;
        }
        numOfPrintedColumns += maxColumnsOnLine;
        cout << endl;
    }
}