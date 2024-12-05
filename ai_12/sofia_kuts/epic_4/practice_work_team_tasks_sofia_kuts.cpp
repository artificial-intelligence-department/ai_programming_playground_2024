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
    string str = to_string(num);
    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string testString;
    cout << "Enter a string to check if it's a palindrome: ";
    cin >> testString;
    if (isPalindrome(testString, 0, testString.length() - 1)) {
        cout << "The string \"" << testString << "\" is a palindrome." << endl;
    } else {
        cout << "The string \"" << testString << "\" is not a palindrome." << endl;
    }
    int testNumber;
    cout << "Enter a number to check if it's a palindrome: ";
    cin >> testNumber;
    if (isPalindrome(testNumber)) {
        cout << "The number " << testNumber << " is a palindrome." << endl;
    } else {
        cout << "The number " << testNumber << " is not a palindrome." << endl;
    }

    return 0;
}
