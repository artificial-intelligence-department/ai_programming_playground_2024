#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str, int start, int end){
    if(start >= end)
    return true;

    if (str[start] != str[end])
    return false;

    return isPalindrome(str, ++start, --end);
}

bool isPalindrome(int num) {
    if (num < 0) return false;

    int origin = num;
    int rev = 0;

    while (num > 0) {
        int digit = num % 10;
        rev = rev * 10 + digit;
        num /= 10;
    }

    return origin == rev;
}


int main(){
    string word;
    int number;

    cout << "Enter a word: ";
    getline(cin, word);

    int start = 0;
    int end = word.size()-1;

    if (isPalindrome(word, start, end)){
        cout << "This word is a palindrome\n";
    }else cout << "This word is not a palindrome\n";


    cout << "Enter a number: ";
    cin >> number;
    if (isPalindrome(number)){
        cout << "This number is a palindrome";
    }else cout << "This number is not a palindrome";
    

    return 0;
}