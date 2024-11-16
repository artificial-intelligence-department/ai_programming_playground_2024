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
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1);
}


int main() {

    string word;
    cout << "Enter a word to check if it is a palindrome: ";
    cin >> word;

    if (isPalindrome (word, 0, word.length() - 1) ) {
        cout << "\"" << word << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << word << "\" is not a palindrome." << endl;
    }

    int number;
    cout << "Enter a number to check if it is a palindrome: ";
    cin >> number;

    if (isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}