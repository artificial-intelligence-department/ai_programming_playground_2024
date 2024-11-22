#include <iostream>
#include <string>
using namespace std;

// Функція для перевірки, чи є рядок паліндромом (залишаємо без змін)
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// Функція для перевірки, чи є число паліндромом
bool isPalindrome(int number) {
    if (number < 0) {
        return false;
    }

    int original = number;
    int reversed = 0;

    while (number > 0) {
        int digit = number % 10; // Отримати останню цифру
        reversed = reversed * 10 + digit; // Додати цифру до зворотного числа
        number /= 10; // Видалити останню цифру
    }

    return original == reversed;
}

int main() {
    // Перевірка рядка
    string str;
    cout << "Введіть слово: ";
    cin >> str;
    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "Введене слово є паліндромом!" << endl;
    } else {
        cout << "Введене слово не є паліндромом." << endl;
    }

    // Перевірка числа
    int number;
    cout << "Введіть число: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << "Введене число є паліндромом!" << endl;
    } else {
        cout << "Введене число не є паліндромом." << endl;
    }

    return 0;
}
