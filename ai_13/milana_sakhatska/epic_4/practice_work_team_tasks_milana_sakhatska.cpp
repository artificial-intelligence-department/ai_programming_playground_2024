#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true; 
    if (str[start] != str[end]) return false; 
    return isPalindrome(str, start + 1, end - 1); 
}


bool isPalindrome(int num) {
    string str = to_string(num); 
    return isPalindrome(str, 0, str.length() - 1); 
}

int main() {
    // Введення слова
    cout << "Enter a word: ";
    string word;
    cin >> word;

    // Перевірка слова
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << word << " is a palindrome!" << endl;
    } else {
        cout << word << " is not a palindrome!" << endl;
    }

    // Введення числа
    cout << "Enter a number: ";
    int num;
    cin >> num;

    // Перевірка числа
    if (isPalindrome(num)) {
        cout << num << " is a palindrome!" << endl;
    } else {
        cout << num << " is not a palindrome!" << endl;
    }

    return 0;
}
