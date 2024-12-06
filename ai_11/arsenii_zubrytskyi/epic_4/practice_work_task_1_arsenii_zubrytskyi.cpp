#include <iostream>
#include <string>
using namespace std;

// Рекурсивна функція для перевірки, чи є слово паліндромом
bool isPalindrome(string str, int start, int end) {
    // Базовий випадок: якщо початкова позиція більша або рівна кінцевій
    if (start >= end) {
        return true;
    }

    // Якщо символи не співпадають, то це не паліндром
    if (str[start] != str[end]) {
        return false;
    }

    // Перевіряємо наступні символи рекурсивно
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для перевірки числа на паліндром
bool isPalindrome(int num) {
    int reversed = 0, original = num;
    
    // Якщо число від'ємне, то це не може бути паліндромом
    if (num < 0) {
        return false;
    }

    // Зворотне число для порівняння
    while (num > 0) {
        int digit = num % 10;   // остання цифра
        reversed = reversed * 10 + digit;
        num /= 10;  // відкидаємо останню цифру
    }

    // Якщо число і його зворотне значення співпадають, то це паліндром
    return original == reversed;
}

int main() {
    // Перевірка на паліндром для слова
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "\"" << word << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << word << "\" is not a palindrome." << endl;
    }

    // Перевірка на паліндром для числа
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
