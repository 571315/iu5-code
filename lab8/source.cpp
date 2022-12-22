#include "header.h"

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
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;
    GetConsoleScreenBufferInfo(hCon, &csbInfo);
    int width = csbInfo.srWindow.Right - csbInfo.srWindow.Left + 1;
    return width - 10;
}

void printMatrix(double** matrix, int n, int m, bool printAsFixed, int precision) {
    int width = getConsoleWidth();

    int rowSize = printAsFixed? 4 + precision : 10 + precision, numOfPrintedColumns = 0, maxColumnsOnLine = width / rowSize;
    while (numOfPrintedColumns < m) {
        for (int i = 0; i < n; ++i) {
            for (int j = numOfPrintedColumns; j < maxColumnsOnLine + numOfPrintedColumns; ++j) {
                if (j == m) 
                    break;

                if (printAsFixed)
                    cout << setw(rowSize) << fixed << setprecision(precision) << matrix[i][j];
                else {
                    cout << setw(rowSize) << scientific << setprecision(precision) << matrix[i][j];
                }
            }
            cout << endl;
        }
        numOfPrintedColumns += maxColumnsOnLine;
        cout << endl;
    }
}