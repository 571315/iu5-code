#include <cstring>
#include <fstream>
#include <iostream>

#define MAX_SIZE 100
#define BUFF_SIZE 31
#define DICTIONARY_FILENAME "dict.txt"

using namespace std;

struct Dictionary {
    char* eng;
    char* rus;
};


int menu();
void addWord(Dictionary* dict, int& n);
void deleteWord(Dictionary* dict, int& n);
void printDict(Dictionary* dict, int& n);
void translateFromEnglish(Dictionary* dict, int& n);
void translateFromRussian(Dictionary* dict, int& n);
void writeToFile(Dictionary* dict, int& n);
void readDictFile(Dictionary* dict, int& n);
void dictCleanUp(Dictionary* dict, int& n);