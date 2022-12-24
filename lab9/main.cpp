#include "dict.h"

using namespace std;

int main() {
    Dictionary dict[MAX_SIZE];
    int n = 0; // Число записей в словаре

    readDictFile(dict, n);
    while (true) {
        switch ( menu() ) {
            case 1:
                addWord(dict, n);
                break;
            case 2:
                deleteWord(dict, n);
                break;
            case 3:
                translateFromEnglish(dict, n);
                break;
            case 4:
                translateFromRussian(dict, n);
                break;
            case 5:
                printDict(dict, n);
                break;
            case 6:
                writeToFile(dict, n);
                break;
            case 7: 
                return 0;
            default:
                cout << "Нужно вводить число от 1 до 7\n";
                break;
        }        
    }

    dictCleanUp(dict, n);  // Нужно не забывать освобождать выделенную память!

    return 0;

}

