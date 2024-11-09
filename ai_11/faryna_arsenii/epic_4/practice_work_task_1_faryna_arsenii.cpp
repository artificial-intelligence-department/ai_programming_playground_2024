#include <iostream>
#include <string>
#include <cctype> // for tolower

using namespace std;

// function for check if word is palindrom
bool isPalindrom(const string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            cout << "Your word isn't a palindrome." << endl;
            return false;
        }
        start++;
        end--;
    }
    cout << "Your word is a palindrome!" << endl;
    return true;
}

// function for check if number is palindrom
bool isPalindrom(int num) {
    
    string str = to_string(num); // Convert number to string
    int start = 0;
    int end = str.length() - 1;
    
    while (start < end) {
        if (str[start] != str[end]) {
            cout << "Your number isn't a palindrome." << endl;
            return false;
        }
        start++;
        end--;
    }
    cout << "Your number is a palindrome!" << endl;
    return true;
}

int main() {
    
    string word;
    int num;
    char option;

    cout << "Enter 'N' for a number or 'W' for a word to check if it's a palindrome:" << endl;
    cin >> option;
    cin.ignore();

    if (option == 'N') {
        cout << "So, Enter a number: ";
        cin >> num;
        isPalindrom(num);
    } else if (option == 'W') {
        cout << "So, Enter a word: ";
        getline(cin, word);

        for (char& c : word){
            c = tolower(c);
        }
        isPalindrom(word, 0, word.length() - 1);
    } else {
        cout << "Invalid option selected." << endl;
    }

    return 0;
}
