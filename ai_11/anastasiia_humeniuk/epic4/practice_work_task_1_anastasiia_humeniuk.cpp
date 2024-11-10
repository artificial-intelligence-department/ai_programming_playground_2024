#include <iostream>
using namespace std;


bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {  
        return true;  
    }
    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);  
    }
    return false; 
}


bool isPalindrome(int number) {
    int reverseNumber = 0;  
    int originalNumber = number;  

    while (number > 0) {  
        int digit = number % 10;
        reverseNumber = reverseNumber * 10 + digit;
        number /= 10;
    }

    return originalNumber == reverseNumber;  
}

int main() {
    int number;
    string word;
    char check;

    cout << "Enter the value you want to check for palindrome. W - word, N - number" << endl;
    cin >> check;

    if (check == 'W' || check == 'w') {
        cout << "Enter the word: ";
        cin >> word;
        cout << (isPalindrome(word, 0, word.length() - 1) ? "Is Palindrome" : "Is Not Palindrome") << endl;
    } 
    else if (check == 'N' || check == 'n') {
        cout << "Enter the number: ";
        cin >> number;
        cout << (isPalindrome(number) ? "Is Palindrome" : "Is Not Palindrome") << endl;
    } 
    else {
        cout << "Wrong value" << endl; 
    }

    return 0;
}
