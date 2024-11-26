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
    if (num < 0) {
        return false; 
    }

    int original = num;
    int reversed = 0;

    while (num != 0) {
        int digit = num % 10;       
        reversed = reversed * 10 + digit; 
        num /= 10;                   
    }

    return original == reversed;
}

int main() {
    string inputStr;
    cout << "Enter a string to check: ";
    cin >> inputStr;

    if (isPalindrome(inputStr, 0, inputStr.size() - 1)) {
        cout << "The string \"" << inputStr << "\" is a palindrome.\n";
    } else {
        cout << "The string \"" << inputStr << "\" is not a palindrome.\n";
    }

    int inputNum;
    cout << "Enter a number to check: ";
    cin >> inputNum;

    if (isPalindrome(inputNum)) {
        cout << "The number " << inputNum << " is a palindrome.\n";
    } else {
        cout << "The number " << inputNum << " is not a palindrome.\n";
    }

    return 0;
}
