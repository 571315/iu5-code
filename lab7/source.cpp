#include "header.h"

int getFileSize(const char* filename) {
    ifstream f(filename, ios::ate | ios::binary);
    int size = f.tellg();
    f.close();
    return size;
}


int getNumberOfWords() {
    ifstream f(KEYS_FILE);
    int res = 0;
    
    char c = ' ';
    while (f.peek() != EOF) {
        f.get(c);
        if (c == ' ')
            ++res;
    }
    return res + 1;
}

int* getKeys(int& numberOfKeys) {
    ifstream f(KEYS_FILE, ios::binary);

    if (!f) {
        cout << "Error at getKeys()! Couldn't open the file!\n";
        return NULL;
    }

    char c;
    
    numberOfKeys = getNumberOfWords();

    int* keys = new int[numberOfKeys];
    for (int i = 0; i < numberOfKeys; ++i)
        keys[i] = 0;

    int i = 0;
    f.seekg(0);
    while (f.peek() != EOF) {
        f.get(c);

        if (c == ' ') {
            keys[i] %= 256;
            ++i;
            continue;
        }

        keys[i] += c;
    }
    return keys;
}

void encodeToFile(const char* filename, int* keys, int numberOfKeys) {
    ifstream if_(filename, ios::binary);
    ofstream of(ENCRYPT_RES_FILE, ios::binary);
    if (!if_ || !of) {
        cout << "Error at encodeToFile()! Couldn't open file\n";
        return;
    }

    char originalChar, encodedChar;

    int i = 0;
    while (if_.peek() != EOF) {
        if_.get(originalChar);
        encodedChar = originalChar + keys[i % numberOfKeys];

        of << encodedChar;
        ++i;
    }

    if_.close();
    of.close();
}

void decodeToFile(const char* filename, int* keys, int numberOfKeys) {
    ifstream if_(filename, ios::binary);
    ofstream of(DECRYPT_RES_FILE, ios::binary);
    if (!if_ || !of) {
        cout << "Error at decodeToFile()! Couldn't open file\n";
        return;
    }

    char encodedChar, decodedChar;

    int i = 0;
    while (if_.peek() != EOF) {
        if_.get(encodedChar);
        decodedChar = encodedChar - keys[i % numberOfKeys];

        of << decodedChar;
        ++i;
    }

    if_.close();
    of.close();
}

int** getStats(int* keys, int numberOfKeys)
{
    // Матрица. Каждый из 256 различных символов могут быть закодированы 256 различными символами.
    // 256-й элемент матрицы -- это общее количество символов, которыми была закодирована буква. 
    // То есть у каждого элемента матрицы 256 + 1 элементов.
    int** stats = new int* [256];
    for (int i = 0; i < 256; ++i) {
        stats[i] = new int[257];
        for (int j = 0; j < 257; ++j) {
            stats[i][j] = 0;
        }
    }

    ifstream if_(ENCRYPT_RES_FILE, ios::binary);
    if (!if_) {
        cout << "Error at getStats()! Couldn't open file\n";
        return NULL;
    }

    char encodedChar;
    unsigned char decodedChar;

    int i = 0;
    while (if_.peek() != EOF) {
        if_.get(encodedChar);
        decodedChar = encodedChar - keys[i % numberOfKeys];
        ++stats[decodedChar][256];
        ++stats[decodedChar][128 + encodedChar];
        ++i;
    }

    if_.close();

    return stats;
}
