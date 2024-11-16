#include <iostream>
#include <cstring>

using namespace std;

// Функція для перевірки на наявність голосних
int check_for_vowels(char word[]) {
    char vowels[] = "AEIOUaeiou";
    for (int i = 0; word[i] != '\0'; i++) {
        for (int j = 0; vowels[j] != '\0'; j++) {
            if (word[i] == vowels[j]) {
                return 1;  // Повертаємо 1, якщо є голосна
            }
        }
    }
    return 0;  // Повертаємо 0, якщо голосних немає
}

int main() {
    char str[256];
    char word[256];

    cout << "Enter a string: ";
    fgets(str, 256, stdin);

    int index = 0;

    // Поки не дійшли до кінця рядка або крапки
    while (str[index] != '.' && str[index] != '\0') {
        int word_len = 0;

        // Пропускаємо пробіли
        while (str[index] == ' ') {
            index++;
        }

        // Збираємо символи в слово
        while (str[index] != '.' && str[index] != ' ' && str[index] != '\0') {
            word[word_len++] = str[index++];
        }

        word[word_len] = '\0';  // Завершуємо слово

        // Перевіряємо, чи немає голосних, і виводимо слово
        if (word_len > 0 && !check_for_vowels(word)) {
            cout << word << endl;
        }
    }

    return 0;
}
    