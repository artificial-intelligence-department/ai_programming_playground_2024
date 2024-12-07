#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Функція для пошуку та друку слів, які співпадають з першим словом
void FindMatchingWords(char str[]) {
    // Розділяємо рядок на слова, використовуючи пробіли
    char* firstWord = strtok(str, " "); // Знаходимо перше слово
    if (firstWord == nullptr) {
        cout << "Рядок не містить слів!" << endl;
        return;
    }

    cout << "Перше слово: " << firstWord << endl;
    cout << "Слова, які співпадають з першим словом: " << endl;

    // Перебираємо інші слова і порівнюємо їх з першим
    char* currentWord = strtok(nullptr, " ");
    while (currentWord != nullptr) {
        // Порівнюємо поточне слово з першим
        if (strcmp(currentWord, firstWord) == 0) {
            cout << currentWord << endl; // Друкуємо, якщо співпадає
        }
        currentWord = strtok(nullptr, " ");
    }
}

int main() {
    char s[256]; // Масив для збереження введеного рядка

    // Ввід рядка користувачем
    cout << "Введіть рядок (до 255 символів, завершуйте крапкою):";
    gets(s);  // Зчитуємо рядок

    // Видаляємо крапку з кінця рядка, якщо вона є
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '.') {
        s[len - 1] = '\0';
    }

    // Викликаємо функцію для пошуку та друку слів
    FindMatchingWords(s);

    return 0;
}
