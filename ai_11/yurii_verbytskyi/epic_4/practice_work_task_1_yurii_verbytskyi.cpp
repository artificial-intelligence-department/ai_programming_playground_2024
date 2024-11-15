#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string& str, int start, int end){
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(long int number) { 
    if (number < 0) {
        return false;
    }
    
    long int original = number;
    long int reversed = 0;

    while (number > 0) {
        long int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }

    return original == reversed;
}

int main() {
    
string str;
cout << "Enter line: ";
cin >> str;

if (isPalindrome(str, 0, str.length() - 1)) {
    cout << "This line is palindrome." << endl;
} else {
    cout << "This line is not palindrome." << endl;
}

int num;
cout << "Enter number: ";
cin >> num;

if (isPalindrome(num)) {
    cout << "This number is palindrome." << endl;
} else {
    cout << "This number is not palindrome." << endl;
}

    return 0;
}





