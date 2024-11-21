#include <iostream>
#include <string>
#include <cmath>
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
bool isPalindrome(int num) {
    if (num < 0){return false;}

    int reversed = 0, original = num;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}


int main() {
    string str;
    cout << "Введіть рядок: ";
    cin >> str;
    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "Рядок є паліндромом.\n";
    } else {
        cout << "Рядок не є паліндромом.\n";
    }


    int num;
    cout << "Введіть число: ";
    cin >> num;
    if (isPalindrome(num)) {
        cout << "Число є паліндромом.\n";
    } else {
        cout << "Число не є паліндромом.\n";
    }

    return 0;
}
