#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true; 
    }
    if (str[start] == str[end]) {
        return isPalindrome(str, ++start, --end);
    }
    return false;
}
bool isPalindrome(int number) {
    int invers = 0;
    int orig = number;
    while (number > 0) {
        invers = invers * 10 + number % 10; 
        number /= 10;
    }
    return orig == invers; 
}
int main() {
    int number;
    cout << "Enter num: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << number << " is palindrome.\n";
    } else {
        cout << number << " isn't palindrome.\n";
    }
    string str;
    cout << "Enter word: ";
    cin >> str;
    if (isPalindrome(str, 0, str.size() - 1)) {
        cout << "\"" << str << "\" is palindrome.\n";
    } else {
        cout << "\"" << str << "\" isn't palindrome.\n";
    }
    return 0;
}