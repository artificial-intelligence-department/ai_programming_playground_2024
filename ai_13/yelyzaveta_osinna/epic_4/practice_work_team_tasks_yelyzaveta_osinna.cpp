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
    if (num < 0) return false; 

    int reversed = 0, original = num;

    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main() {
    cout << "Введіть слово або число: ";
    string input;
    cin >> input;

    bool is_numeric = true;

    for (char c : input) {
        if (!isdigit(c)) {
            is_numeric = false;
            break;
        }
    }

    if (is_numeric) {
        int number = stoi(input);
        if (isPalindrome(number)) {
            cout << "Число " << number << " є паліндромом." << endl;
        } else {
            cout << "Число " << number << " не є паліндромом." << endl;
        }
    } else {
        if (isPalindrome(input, 0, input.size() - 1)) {
            cout << "Рядок \"" << input << "\" є паліндромом." << endl;
        } else {
            cout << "Рядок \"" << input << "\" не є паліндромом." << endl;
        }
    }

    return 0;
}
