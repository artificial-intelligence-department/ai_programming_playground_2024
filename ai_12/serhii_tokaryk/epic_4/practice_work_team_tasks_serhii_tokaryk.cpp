#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
     return true; 
    }
    if (str[start] != str[end]){ 
     return false; 
    }
     return isPalindrome(str, start + 1, end - 1); 
}


bool isPalindrome(int num, int reversed = 0, int original = -1) {
    if (original == -1) original = num; 
    if (num == 0) return original == reversed; 

     return isPalindrome(num / 10, reversed, original); 
}


int main() {
    string word;
    int number;

    cout << "Введіть слово для перевірки: ";
    cin >> word;
    if (isPalindrome(word, 0, word.length() - 1)) {
        cout << "Це слово є паліндромом." << endl;
    } 
    
    else {
        cout << "Це слово не є паліндромом." << endl;
    }

    cout << "Введіть число для перевірки: ";
    cin >> number;
    if (isPalindrome(number)) {
        cout << "Це число є паліндромом." << endl;
    } 
    
    else {
        cout << "Це число не є паліндромом." << endl;
    }

    return 0;
}
