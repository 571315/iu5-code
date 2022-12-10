#include <iostream>
#include <ctime>  // time
#include <iomanip> // для красивой таблицы
#include <cmath>
#include <cstring>

using namespace std;


// Сортировка методом выбора максимального (минимального) элемента
void selectionSort(int* array, int size, bool reverse, int& numberOfComps, int& numberOfSwaps) 
{
    numberOfComps = 0, numberOfSwaps = 0;
    int minIndex;

    for (int i = 0; i < size - 1; ++i)
    {
        minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            ++numberOfComps;
            if ((reverse && array[j] > array[minIndex]) || (!reverse && array[j] < array[minIndex])) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(array[i], array[minIndex]);
            ++numberOfSwaps;
        }

    }
}


// Сортировка методом пузырькового всплытия
void bubbleSort(int* array, int size, bool reverse, int& numberOfComps, int& numberOfSwaps) {
    numberOfComps = 0, numberOfSwaps = 0;
    bool wasAnythingSwapped;

    for (int i = 0; i < size - 1; ++i) {
        wasAnythingSwapped = false;

        // Last i elements are already in place
        for (int j = 0; j < size - 1 - i; ++j) {
            ++numberOfComps;
            if ((reverse && array[j] < array[j + 1]) || (!reverse && array[j] > array[j + 1])) {
                swap(array[j], array[j + 1]);
                ++numberOfSwaps;
                if (!wasAnythingSwapped) wasAnythingSwapped = true;
            }
        }
        if (!wasAnythingSwapped)
            break;
    }
}


int iRandom(int a, int b)       	 	// целое из [a,b]
{
    const unsigned long long r = rand();
    return a + (b - a + 1) * r / RAND_MAX;
}


// Выводит массив
void printArray(int* array, int size) {
    for (int i = 0; i < size; ++i)
        cout << array[i] << ' ';
    cout << endl;
}


// int* array -- массив, int size -- размер, bool reverse -- в каком порядке нужно сортировать. Прямой = false, обратный = true
void printArraySortData(int* array, int size, bool reverse)
{
    int numberOfComparisons, numberOfSwaps;

    int* arrayCopy = new int[size];
    memcpy(arrayCopy, array, size * sizeof(*array));  // memcpy :P


    cout << "SELECTION SORT\n";
    selectionSort(arrayCopy, size, reverse, numberOfComparisons, numberOfSwaps);
    cout << "Количество сравнений: " << numberOfComparisons << "\nКоличество перестановок: " << numberOfSwaps << "\n";
    printArray(arrayCopy, size);

    memcpy(arrayCopy, array, size * sizeof(*array));  // ArrayCopy был изменен из-за сортировки => он теперь не копия array. Сделаем его снова копией исходного массива.

    cout << "\n\nBUBBLE SORT\n";
    bubbleSort(arrayCopy, size, reverse, numberOfComparisons, numberOfSwaps);
    cout << "Количество сравнений: " << numberOfComparisons << "\nКоличество перестановок: " << numberOfSwaps << "\n";
    printArray(arrayCopy, size);
}


void showPerformanceSizeDependency()
{
    int* arr;
    int* arrCopy;
    int size;
    int numberOfComparisons, numberOfSwaps;

    for (int i = 1; i < 4; ++i)
    {
        // Инициализация массива
        size = pow(10, i);

        arr = new int[size];
        arrCopy = new int[size];
        for (int j = 0; j < size; ++j)
            arr[j] = arrCopy[j] = iRandom(1, 9);

        // Сортировка + вывод статистики
        selectionSort(arr, size, false, numberOfComparisons, numberOfSwaps);
        cout << "+-----------------------------------------------------------------+\n";
        cout << "|" << setw(32) << "N  = " << setw(5) << size << setw(30) << "|\n";
        cout << "|----------------+----------------------+-------------------------|\n";
        cout << "| ТИП СОРТИРОВКИ | КОЛИЧЕСТВО СРАВНЕНИЙ | КОЛИЧЕСТВО ПЕРЕСТАНОВОК |\n";
        cout << "|----------------+----------------------+-------------------------|\n";
        cout << "|    ВЫБОРОМ     |" << setw(14) << numberOfComparisons << "        |" 
             << setw(14) << numberOfSwaps << setw(13) <<  "|\n";

        bubbleSort(arrCopy, size, false, numberOfComparisons, numberOfSwaps);
        cout << "|----------------+----------------------+-------------------------|\n";
        cout << "|   ПУЗЫРЬКОМ    |" << setw(14) << numberOfComparisons << setw(9) << "|" 
             << setw(16) << numberOfSwaps << setw(11) << "|\n";
        printf("+----------------+----------------------+-------------------------+\n\n\n");

        delete[] arr;
        delete[] arrCopy;
    }
}


int main() 
{
    //////////////////////////////////// ИНИЦИАЛИЗАЦИЯ МАССИВА /////////////////////////////////////
    const int n = 5;
    int a[n], aCopy[n], numberOfComparisons, numberOfSwaps;

    srand((unsigned int) time(NULL));
    
    for (int i = 0; i < n; i++)  // цикл инициализации массива
    {
        a[i] = aCopy[i] = iRandom(1, 9);  // целая случайная величина
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    //////////////////////////////////////// СОРТИРОВКА ////////////////////////////////////////
    cout << "\n---------------------- СОРТИРОВКИ ДЛЯ ИСХОДНОГО МАССИВА -------------------------\n";
    printArraySortData(a, n, false);

    cout << "\n---------- СОРТИРОВКИ В ПРЯМОМ ПОРЯДКЕ ДЛЯ УЖЕ ОТСОРТИРОВАННОГО В ПРЯМОМ ПОРЯДКЕ МАССИВА ----------\n";
    selectionSort(aCopy, n, false, numberOfComparisons, numberOfSwaps);
    printArraySortData(aCopy, n, false);

    cout << "\n--------------- СОРТИРОВКИ В ОБРАТНОМ ПОРЯДКЕ ДЛЯ УЖЕ ОТСОРТИРОВАННОГО В ПРЯМОМ ПОРЯДКЕ МАССИВА ---------------\n";
    selectionSort(aCopy, n, false, numberOfComparisons, numberOfSwaps);
    printArraySortData(aCopy, n, true);

    showPerformanceSizeDependency();

    return 0;
}
