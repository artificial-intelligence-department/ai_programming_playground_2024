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


bool isPalindrome(int num) {
   
    if (num < 0) {
        return false;
    }
    
    int rev = 0;
    int orig = num;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    return orig == rev;
}

int main() {
    string str;
    cout << "Введіть рядок: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1)) {
        cout << "Рядок є паліндромом." << endl;
    } else {
        cout << "Рядок не є паліндромом." << endl;
    }

    int num;
    cout << "Введіть число: ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << "Число є паліндромом." << endl;
    } else {
        cout << "Число не є паліндромом." << endl;
    }

    return 0;
}
