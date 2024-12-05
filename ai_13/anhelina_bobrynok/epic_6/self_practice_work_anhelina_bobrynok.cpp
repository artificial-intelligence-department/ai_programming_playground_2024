#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

// Функція для перевірки, чи є слово паліндромом
bool isPalindrome(const string& word) {
    string lowerWord = word;
    transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower); // Приведення до нижнього регістру
    string reversedWord = lowerWord;
    reverse(reversedWord.begin(), reversedWord.end()); // Створення оберненої копії
    return lowerWord == reversedWord; // Перевірка на рівність
}

int main() {
    string line;
    int palindromeCount = 0;

    // Зчитуємо рядки до кінця вхідних даних
    while (getline(cin, line)) {
        stringstream ss(line);
        string word;

        // Розбиваємо рядок на слова
        while (ss >> word) {
            if (isPalindrome(word)) {
                palindromeCount++;
            }
        }
    }

    // Виводимо результат
    cout << palindromeCount << endl;
    return 0;
}













