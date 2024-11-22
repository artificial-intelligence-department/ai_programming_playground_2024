#include <iostream>
#include <string>
using namespace std;

int main() {
    string t, s;// Використано цілочисельні змінні
    cin >> t >> s;

    int len_t = t.size();// Використано цілочисельні змінні для довжини рядків
    int len_s = s.size();

    for (int i = 0; i <= len_t - len_s; i++) {// Цикл for для перебору всіх можливих позицій у рядку t
        bool can_place = true;

        
        for (int j = 0; j < len_s; j++) { // Цикл for для перевірки відповідності символів
        
            if (t[i + j] != '?' && t[i + j] != s[j]) {// Умовний оператор if для перевірки символів
                can_place = false;
                break; // Оператор break для виходу з циклу
            }
        }

        if (can_place) { // Умовний оператор if для виведення результату
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;// Оператор виведення результату
    return 0;
}
