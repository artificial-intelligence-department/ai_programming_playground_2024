#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    // Базовий випадок
    if (start >= end) {
        return true;
    }
    // Якщо символи на поточних позиціях не збігаються
    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    // Перетворення числа на рядок
    string str = to_string(number);
    // Виклик рекурсивної функції для рядків
    return isPalindrome(str, 0, str.length() - 1);
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
