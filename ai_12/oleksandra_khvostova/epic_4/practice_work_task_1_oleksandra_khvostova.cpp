#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція для перевірки паліндрома для рядків
bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true; // Порожній рядок або один символ - паліндром
    }
    if (str[start] != str[end]) {
        return false; // Якщо перший і останній символи різні, то це не паліндром
    }
    return isPalindrome(str, start + 1, end - 1); // Рекурсивний виклик для підрядка
}

// Перевантажена функція для перевірки паліндрома для цілих чисел
bool isPalindrome(int num) {
    if (num < 0) {
        return false; // Від'ємні числа не можуть бути паліндромами
    }
    if (num == 0) {
        return true; // Нуль є паліндромом
    }
    int reversedNum = 0;
    int originalNum = num;
    while (num != 0) {
        int remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int main() {
    string str;
    int num;
    cout<<"Enter the string: ";
    cin>>str;
    cout<<"Enter the integer: ";
    cin>>num;

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << str << " is a palindrome" << endl;
    } else {
        cout << str << " is not a palindrome" << endl;
    }

    if (isPalindrome(num)) {
        cout << num << " is a palindrome" << endl;
    } else {
        cout << num << " is not a palindrome" << endl;
    }

    return 0;
}