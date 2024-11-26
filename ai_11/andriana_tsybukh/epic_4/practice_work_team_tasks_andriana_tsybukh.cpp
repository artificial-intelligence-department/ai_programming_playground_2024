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
    if (number < 0) {
        return false;
    }

    int original = number;
    int reversed = 0;

    while (number > 0) {
        int lastDigit = number % 10;
        reversed = reversed * 10 + lastDigit;
        number /= 10;
    }
    return original == reversed;
}

int main() {
    string word;
    int number;

    cout << "Введіть слово: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) { 
        cout << word << " є паліндромом." << endl;
    } else {
        cout << word << " не є паліндромом." << endl;
    }

    cout << "Введіть число: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " є паліндромом." << endl;
    } else {
        cout << number << " не є паліндромом" << endl;
    }

    return 0;
}