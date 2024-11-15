#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Рекурсивна функція для перевірки рядків
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true; // Базовий випадок
    if (str[start] != str[end]) return false; // Символи не збігаються
    return isPalindrome(str, start + 1, end - 1); // Рекурсивний виклик
}

// Перевантажена функція для цілих чисел
bool isPalindrome(int number) {
    // Перетворення числа на рядок
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1); // Використання функції для рядків
}

// Головна функція
int main() {
    // Тестування функції для рядків
    string word;
    cout << "Enter a word: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palindrome!" << endl;
    } else {
        cout << word << " is not a palindrome!" << endl;
    }

    // Тестування функції для чисел
    int number;
    cout << "Enter a number: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << number << " is a palindrome!" << endl;
    } else {
        cout << number << " is not a palindrome!" << endl;
    }

    return 0;
}
