#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    char s[256];  // Масив для збереження рядка
    cout << "Введіть рядок: ";  // Повідомлення для користувача
    fgets(s, sizeof(s), stdin);  // Вводимо рядок (не більше 255 символів)

    // Видаляємо можливий символ нового рядка, який може бути зчитаний fgets
    s[strcspn(s, "\n")] = 0;

    // Розбиваємо рядок на слова
    char* word = strtok(s, " ");  // Розбиваємо по пробілах

    cout << "Слова з однією цифрою:" << endl;
    while (word != nullptr) {
        int digitCount = 0;  // Лічильник цифр у слові

        // Перевіряємо кожен символ слова
        for (int i = 0; word[i] != '\0'; i++) {
            if (isdigit(word[i])) {  // Якщо символ є цифрою
                digitCount++;
            }
        }

        // Якщо в слові лише одна цифра
        if (digitCount == 1) {
            cout << word << endl;  // Виводимо слово
        }

        word = strtok(nullptr, " ");  // Отримуємо наступне слово
    }

    return 0;
}
