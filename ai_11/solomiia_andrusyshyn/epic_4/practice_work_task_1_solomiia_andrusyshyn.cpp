#include <iostream>
using namespace std;

bool checkPalindrome(const char* word, int length) {
    int left = 0, right = length - 1;

    while (left < right) {
        if (word[left] != word[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

bool checkPalindromeNumber(int num) {
    int reversed = 0, temp = num;

    while (temp > 0) {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    return num == reversed;
}

int main() {
    char type;
    cout << "Choose type to check for palindrome (W for word, N for number): ";
    cin >> type;

    if (type == 'W' || type == 'w') {
        char word[100];
        cout << "Enter a word: ";
        cin >> word;

        int length = 0;
        while (word[length] != '\0') {
            length++;
        }

        if (checkPalindrome(word, length)) {
            cout << "The word is a palindrome!" << endl;
        } else {
            cout << "The word is not a palindrome." << endl;
        }
    } else if (type == 'N' || type == 'n') {
        int number;
        cout << "Enter a number: ";
        cin >> number;

        if (checkPalindromeNumber(number)) {
            cout << "The number is a palindrome!" << endl;
        } else {
            cout << "The number is not a palindrome." << endl;
        }
    } else {
        cout << "Invalid input. Please enter W for word or N for number." << endl;
    }

    return 0;
}
