#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str, int start, int end);
bool isPalindrome(int num, int originalNum, int reversedNum);

int main() {
    string type;

    cout << "Enter type: ";
    cin >> type;

    if (type == "str") {
        string str;
        cout << "Enter string: ";
        cin >> str;

        int start = 0, end = str.length() - 1;

        if (isPalindrome(str, start, end)) {
            cout << "This is a palindrome\n";
        } else cout << "This is not a palindrome\n";
        
    } else if (type == "int") {
        int num;
        cout << "Enter number: ";
        cin >> num;

        if (num >= 0 && isPalindrome(num, num, 0)) {
            cout << "This is a palindrome\n";
        } else cout << "This is not a palindrome\n";
        
    } else cout << "Wrong input\n";

    return 0;
}


bool isPalindrome(const string &str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, ++start, --end); 
}


bool isPalindrome(int num, int originalNum, int reversedNum) {
    if (num == 0) {
        return originalNum == reversedNum;
    }

    int digit = num % 10;
    reversedNum = reversedNum * 10 + digit;

    return isPalindrome(num / 10, originalNum, reversedNum);
}



