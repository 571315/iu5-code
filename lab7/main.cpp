#include "header.h"

int main() {
    system("chcp 1251");
    int* keys, numberOfKeys;
    keys = getKeys(numberOfKeys);

    encodeToFile(INPUT_FILE, keys, numberOfKeys);
    decodeToFile(ENCRYPT_RES_FILE, keys, numberOfKeys);

    unsigned char c;
    int overallCodedTimes;

    int** charStats = getStats(keys, numberOfKeys);

    cout << "Enter letter of which stats you want to get ('.' -- exit)\n";
    cin >> c;

    while (c != '.') {
        overallCodedTimes = charStats[c][256];

        if (overallCodedTimes > 0) {
            cout << "Letter " << c << " was encoded as " << overallCodedTimes << " times\n";
            // STATISTICS
            for (int i = 1; i < 256; ++i) {
                if (charStats[c][i] != 0)
                    cout << "With symbol " << (unsigned char)i << " (" << (int)i << ") " << " " << charStats[c][i] << " times\n";
            }
        } 
        else
            cout << "The letter is not present in the text\n";

        cout << "\nEnter letter of which stats you want to get ('.' -- exit)\n";
        cin >> c;
    }

    for (int i = 0; i < 256; ++i)
        delete[] charStats[i];
    delete[] charStats;
    delete[] keys;
}