#include <iostream>
#include <cstring>  // для роботи зі стрічками
#include <algorithm>  // для сортування

using namespace std;

// Функція для сортування символів у слові
void sortWord(char* word) {
    int length = strlen(word);
    sort(word, word + length);  // Сортуємо символи в слові
}

int main() {
    char str[256]; // Вхідний рядок, максимальна довжина 255 символів + 1 для '\0'

    // Читання рядка
    cout << "Enter a string: (max length 255 characters)" << endl;
    fgets(str, sizeof(str), stdin); 

    // Видаляємо зайвий символ нового рядка, якщо він є
    size_t str_len = strlen(str);  // Обчислюємо довжину рядка один раз
	if (str_len > 0 && str[str_len - 1] == '\n') { 
		str[str_len - 1] = '\0'; 
    }

    int i = 0;
    char word[256];  // Буфер для одного слова
    int wordIndex = 0;

    bool firstWord = true;  // Для коректного виведення пробілів

	while (i <= str_len) { // Цикл по всім символам рядка
        if (str[i] != ' ' && str[i] != '\0') {
            // Збираємо символи слова
            word[wordIndex++] = str[i];
        }
        else {
            // Коли слово закінчено, сортуємо його і виводимо
            if (wordIndex > 0) {
                word[wordIndex] = '\0';
                sortWord(word);
                if (!firstWord) {
                    cout << " ";  // Виводимо пробіл перед кожним словом після першого
                }
                cout << word;
                wordIndex = 0;  // Очищаємо слово
                firstWord = false;  // Після першого слова наступні будуть з пробілами
            }
        }
        i++;
    }
    cout << endl;
    return 0;
}

// використано fgets замість gets оскільки gets є застарілим і небезпечним(може викликати переповнення буфера) 