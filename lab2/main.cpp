#include <iostream>

using namespace std;

int main() {
    while (true) {
        // Windows... Russian lang support
        // system("chcp 65001");
        // setlocale(LC_ALL, NULL);

        int h, m;
        cin >> h >> m;

        // Проверить корректность введеных данных
        if (!(h >= 0 && h <= 23 && m >= 0 && m < 60)) {
            cout << "Ошибка! Введены недопустимые значения!\n";
            continue;
        }

        if (h == 12 && m == 0) {
            cout << "полдень\n";
            continue;
        } else if (h == 0 && m == 0) {
            cout << "полночь\n";
            continue;
        }

        // Обработка часов
        int hh = h; // Будет использоваться для определения времени суток
        if (h > 12)
            h -= 12;
        else if (h == 0)
            h = 12;
        cout << h << " час";

        if (h > 1 && h < 5)
            cout << "а";
        else if (h > 4 && h < 21)
            cout << "ов";

        // Обработка минут
        if (m != 0) {
            cout << ' ' << m << " минут";
            int lastMDigit = m % 10;
            if (lastMDigit == 1 && m != 11)
                cout << "а";
            else if (lastMDigit > 1 && lastMDigit < 5 && (m / 10) != 1)
                cout << "ы";
        }

        // Вывод времени суток
        if (hh >= 5 && hh <= 12)
            cout << " утра";
        else if (hh > 12 && hh < 18)
            cout << " дня";
        else if (hh >= 18 && hh <= 23)
            cout << " вечера";
        else
            cout << " ночи";

        if (m == 0)
            cout << " ровно";

        cout << endl;
    }
    return 0;
}
