#include <iostream>
#include <string>
using namespace std;

//Рекурсивна функція для перевірки, чи є рядок паліндромом
bool isPalindrome(const string& str, int start, int end) {
    // Базовий випадок: коли індекс start більше або дорівнює end
    if (start >= end) {
        return true;
    }

    // Якщо символи на початку і в кінці не співпадають
    if (str[start] != str[end]) {
        return false;
    }

    // Рекурсивно перевіряємо наступні символи
    return isPalindrome(str, start + 1, end - 1);
}

// Функція для перевірки, чи є число паліндромом
bool isPalindrome(int num) {
    // Якщо число негативне, воно не може бути паліндромом
    if (num < 0) return false;

    // Перетворюємо число в рядок і викликаємо функцію для рядка
    string str = to_string(num);
    return isPalindrome(str, 0, str.size() - 1);
}

int main() {
    // Приклад перевірки для рядка
    string word = "radar";
    if (isPalindrome(word, 0, word.size() - 1)) {
        cout << word << " is a palindrome!" << endl;
    }
    else {
        cout << word << " is not a palindrome!" << endl;
    }

    // Приклад перевірки для числа
    int number = 12321;
    if (isPalindrome(number)) {
        cout << number << " is a palindrome!" << endl;
    }
    else {
        cout << number << " is not a palindrome!" << endl;
    }

    return 0;
}
