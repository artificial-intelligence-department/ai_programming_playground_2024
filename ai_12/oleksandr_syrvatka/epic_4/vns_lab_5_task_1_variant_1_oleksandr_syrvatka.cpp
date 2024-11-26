#include <iostream>
using namespace std;

// Функція для формування слів
void extractWords(char arr[], char result[][60], int &wordCount) {
    int j = 0; // Індекс для слова
    wordCount = 0; // Лічильник кількості слів

    // Проходимо по кожному символу у рядку
    for (int i = 0; arr[i] != '\0'; i++) {
        // Якщо зустріли 0 то кінець слова
        if (arr[i] == '0') {
            result[wordCount][j] = '\0'; // Завершуємо поточне слово
            wordCount++; // Переходимо до наступного слова
            j = 0; // Починаємо нове слово
        } else {
            result[wordCount][j] = arr[i]; // Додаємо символ до слова
            j++;
        }
    }
}

void print(char arr[][60], int rowCount) {
    for (int row = 0; row < rowCount; row++) {
        char words[10][60]; 
        int wordCount = 0;

        extractWords(arr[row], words, wordCount);

        cout << "(";
        for (int i = 0; i < wordCount; i++) {
            cout << words[i];
            if (i != wordCount - 1) cout << ",";
        }
        cout << ")";
    }
    cout << endl;
}

int main() {
    cout << "Введіть кількість рядків ";
    int MAX_ROWS;
    cin >> MAX_ROWS;
    char arr[MAX_ROWS][60];

    // Введення рядків користувачем
    cout << "Введіть " << MAX_ROWS << " рядки, що складаються з цифр, які закінчуються на 0:" << endl;
    for (int i = 0; i < MAX_ROWS; i++) {
        cout << "Рядок " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Результат: ";
    print(arr, MAX_ROWS);

    return 0;
}
