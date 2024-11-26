#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int number) {
    if (number < 0) return false;
    int original = number, reversed = 0;
    while (number > 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return original == reversed;
}

int main() {
    string str;
    cout << "Введіть рядок для перевірки: ";
    cin >> str;
    if (isPalindrome(str, 0, str.size() - 1)) {
        cout << "Рядок " << str << " є паліндромом" << endl;
    } else {
        cout << "Рядок " << str << " не є паліндромом" << endl;
    }

    int number;
    cout << "Введіть число для перевірки: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << "Число " << number << " є паліндромом" << endl;
    } else {
        cout << "Число " << number << " не є паліндромом" << endl;
    }

    return 0;
}
