#include <iostream>
#include <string>
using namespace std;

// Рекурсивна функція для перевірки рядків
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true; // Базовий випадок
    if (str[start] != str[end]) return false; // Якщо символи не співпадають
    return isPalindrome(str, start + 1, end - 1); // Рекурсія для підрядка
}

// Перевантажена функція для чисел
bool isPalindrome(int num, int reversed = 0, int original = -1) {
    if (original == -1) original = num; // Початкове значення
    if (num == 0) return original == reversed; // Базовий випадок

    reversed = reversed * 10 + num % 10; // Формування перевернутого числа
    return isPalindrome(num / 10, reversed, original); // Рекурсія
}

// Тестування
int main() {
    string word;
    int number;

    cout << "Введіть слово для перевірки: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "Це слово є паліндромом.\n";
    } else {
        cout << "Це слово не є паліндромом.\n";
    }

    cout << "Введіть число для перевірки: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << "Це число є паліндромом.\n";
    } else {
        cout << "Це число не є паліндромом.\n";
    }

    return 0;
}
