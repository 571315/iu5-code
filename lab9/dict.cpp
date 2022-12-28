#include "dict.h"
#include <cstring>


int menu() {
    cout << "Выберите действие:\n\
             1 -- добавить слово в словарь\n\
             2 -- удалить слово из словаря\n\
             3 -- перевод слов с английского на русский\n\
             4 -- перевод слов с русского на английский\n\
             5 -- просмотр словаря (вывод на экран словаря из ОП)\n\
             6 -- вывод словаря в файл\n\
             7 -- выход\n";
    int ans;
    cin >> ans;
    return ans;
}


void addWord(Dictionary* dict, int& n) {
    if (n == MAX_SIZE) {
        cout << "Ошибка! В словаре уже максимальное количество слов!\n";
        return;
    }

    cout << "Введите через пробел слова, которые хотите добавить (сначала английское слово, затем русское)\n";
    char buff[BUFF_SIZE];
    if (n == 0) {
        cin >> buff;
        dict[0].eng = new char[strlen(buff)];
        strcpy(dict[0].eng, buff);

        cin >> buff;
        dict[0].rus = new char[strlen(buff)];
        strcpy(dict[0].rus, buff);
        ++n;
        return;
    }
    
    cin >> buff;
    
    // Находим место в массиве, куда мы закинем новую пару слов
    int i = n;
    while (i > 0 && strcmp(buff, dict[i - 1].eng) < 0) {
        --i;
    }

    // Сдвигаем слова после индекса i направо
    for (int j = n; j >= i; --j) {
        dict[j] = dict[j - 1];
    }

    dict[i].eng = new char[strlen(buff)];
    strcpy(dict[i].eng, buff);
    cin >> buff;
    dict[i].rus = new char[strlen(buff)];
    strcpy(dict[i].rus, buff);
    ++n;
}

void deleteWord(Dictionary* dict, int& n) {
    cout << "Введите слово, которое хотите удалить\n";
    char buff[BUFF_SIZE];
    cin >> buff;

    for (int i = 0; i < n; ++i) {
        if (strcmp(dict[i].eng, buff) == 0 || strcmp(dict[i].rus, buff) == 0) {
            delete dict[i].eng;
            delete dict[i].rus;
            for (int j = i; j < n - 1; ++j) {
                dict[j] = dict[j + 1];
            }

            --n;
            cout << "Слово успешно удалено\n";
            return;
        }
    }
    cout << "Ошибка! Такого слова нет в словаре!\n";
}


void printDict(Dictionary* dict, int& n) {
    if (n == 0)
        cout << "Словарь пустой\n";
    else
        for (int i = 0; i < n; ++i)
            cout << dict[i].eng << ' ' << dict[i].rus << endl;
}

void translateFromEnglish(Dictionary* dict, int& n) {
    char buff[BUFF_SIZE];
    cout << "Введите слово, которое нужно перевести\n";
    cin >> buff;

    int l = 0, r = n - 1, mid, res;
    while (l <= r) {
        mid = (l + r) / 2;

        res = strcmp(dict[mid].eng, buff);

        if (res == 0) {
            cout << "Перевод слова " << buff << ": " << dict[mid].rus << endl;
            return;
        } 
        else if (res > 0) {
            r = mid - 1;
        } 
        else {
            l = mid + 1;
        }
    }

    cout << "Ошибка! Слово не найдено!\n";
}

void translateFromRussian(Dictionary* dict, int& n) {
    char buff[BUFF_SIZE];
    cout << "Введите слово, которое нужно перевести\n";
    cin >> buff;

    for (int i = 0; i < n; ++i) {
        if (strcmp(dict[i].rus, buff) == 0) {
            cout << "Перевод слова " << buff << ": " << dict[i].eng << endl;
            return;
        }
    }
    cout << "Слово не найдено в словаре!\n";
}

void writeToFile(Dictionary* dict, int& n) {
    ofstream f(DICTIONARY_FILENAME);

    if (!f) {
        cerr << "Ошибка! невозможно открыть файл dict.txt для записи\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        f << dict[i].eng << ' ' << dict[i].rus << endl;
    }
    
    f.close();
}


void readDictFile(Dictionary* dict, int& n) {
    ifstream f(DICTIONARY_FILENAME);
    if (!f) {
        cerr << "Ошибка! невозможно открыть файл dict.txt для чтения\n";
        return;
    }
    
    n = 0;
    char buff[BUFF_SIZE];
    while (!f.eof()) {
        f >> buff;
        if (f.eof())
            break;
        dict[n].eng = new char[strlen(buff)];  // Выделяем столько памяти, сколько необходимо
        strcpy(dict[n].eng, buff);

        f >> buff;
        dict[n].rus = new char[strlen(buff)];
        strcpy(dict[n].rus, buff);
        ++n;
    }
    f.close();
}

void dictCleanUp(Dictionary* dict, int& n) {
    for (int i = 0; i < n; ++i) {
        delete dict[i].eng;
        delete dict[i].rus;
    }
}