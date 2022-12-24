#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


struct I_print  
{
    // данные для печати результатов интегрирования
    const char *name; // название функции
    double i_sum;
    // значение интегральной суммы
    double i_toch;
    // точное значение интеграла
    int n;
    // число разбиений области интегрирования
    // при котором достигнута требуемая точность
};

void PrintTabl(I_print i_prn[], int k);