#include <iostream>
#include <string>
#include <cmath>

using namespace std;



bool is_palindrome(const string& str, int start, int end) {

    if (start >= end) {

        return true;
    }
    if (str[start] != str[end]) {

        return false;

    }

    return is_palindrome(str, start + 1, end - 1);
}


bool is_palindrome(int num) {

    if (num < 0) return false;

    int original = num;

    int reversed = 0;


    while (num > 0) {

        int digit = num % 10;

        reversed = reversed * 10 + digit;

        num /= 10;
    }


    return original == reversed;
}

int main() {

    string str;

    cout << "Enter a string: ";

    cin >> str;

    if (is_palindrome(str, 0, str.length() - 1)) {


        cout << "The string is a palindrome." << endl;
    } else {

        cout << "The string is not a palindrome." << endl;
    }


    int num;

    cout << "Enter a number: ";

    cin >> num;


    if (is_palindrome(num)) {

        cout << "The number is a palindrome." << endl;

    } else {

        cout << "The number is not a palindrome." << endl;

    }


    return 0;
}
