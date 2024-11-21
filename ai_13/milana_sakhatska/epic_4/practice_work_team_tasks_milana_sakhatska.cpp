#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true; // Базовий випадок
    if (str[start] != str[end]) return false; // Якщо символи не співпадають
    return isPalindrome(str, start + 1, end - 1); // Рекурсивний виклик
}

// Перевантажена функція для перевірки, чи є число паліндромом
bool isPalindrome(int num) {
    string str = to_string(num); // Перетворюємо число в рядок
    return isPalindrome(str, 0, str.length() - 1); // Використовуємо функцію для рядків
}

int main() {
    // Введення слова
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // Перевірка слова
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palindrome!" << endl;
    } else {
        cout << word << " is not a palindrome!" << endl;
    }

    // Введення числа
    cout << "Enter a number: ";
    int num;
    cin >> num;

    // Перевірка числа
    if (isPalindrome(num)) {
        cout << num << " is a palindrome!" << endl;
    } else {
        cout << num << " is not a palindrome!" << endl;
    }

    return 0;
}
