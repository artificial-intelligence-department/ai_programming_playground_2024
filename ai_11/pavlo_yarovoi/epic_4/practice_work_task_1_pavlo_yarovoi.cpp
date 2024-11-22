#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
    if (num < 0) return false;
    int original = num;
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}
 
int main() {
    string s;
    cout << "Enter a word: ";
    cin >> s;
    if (isPalindrome(s, 0, s.length() - 1)) {
        cout << s << " is a palindrome" << endl;
    } else {
        cout << s << " isnt a palindrome" << endl;
    }
    
    int num;
    cout << "Enter a number: ";
    cin >> num;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome" << endl;
    } else {
        cout << num << " isnt a palindrome" << endl;
    }

    return 0;
}
