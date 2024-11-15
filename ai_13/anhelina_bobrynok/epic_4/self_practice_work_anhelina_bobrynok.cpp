#include <iostream>
#include <string>
using namespace std;

// Рекурсивна функція для перевірки паліндрома для рядків
bool isPalindrome(const string& str, int start, int end) {

    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }
    
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для перевірки паліндрома для цілих чисел
bool isPalindrome(int num) {
    if (num < 0) {
        return false;
    }

    string str = to_string(num);

    return isPalindrome(str, 0, str.length() - 1);
}

int main() {
    string word;
    int number;

    cout<<"enter a word\n";
    cin>>word;
    cout<<"enter a number\n";
    cin>>number;
    
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palindrome!" << endl;
    } else {
        cout << word << " is not a palindrome!" << endl;
    }
    if (isPalindrome(number)) {
        cout << number << " is a palindrome!" << endl;
    } else {
        cout << number << " is not a palindrome!" << endl;
    }

    return 0;
}








