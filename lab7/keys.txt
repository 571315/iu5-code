#include <fstream>
#include <iostream>

using namespace std;

#define KEYS_FILE "keys.txt"
#define INPUT_FILE "input.txt"
#define ENCRYPT_RES_FILE "encrypted.txt"
#define DECRYPT_RES_FILE "decrypted.txt"


int getFileSize(const char* filename);
int getNumberOfWords();
int* getKeys(int& numberOfKeys);
void encodeToFile(const char* filename, int* keys, int numberOfkeys);
void decodeToFile(const char* filename, int* keys, int numberOfkeys);
int** getStats(int* keys, int numberOfKeys);