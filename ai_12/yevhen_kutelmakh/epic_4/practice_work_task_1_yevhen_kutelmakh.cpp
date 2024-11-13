#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPalindrome(const string &str, int finish, int start=0) {
    if(str[start]==str[finish]) {
        if(start==finish) return true;
        else return isPalindrome(str, finish - 1, start + 1);
    }
    return false;
}

bool isPalindrome(int num) {
    if(num<10) return true;
    else {
        int first = num, last;
        last = num % 10;
        int counter = 0;
        while(first>=10) {
            first /= 10;
            counter++;
        }
        if(first!=last) return false;
        else {
            num /= pow(10,counter);
            num /= 10;
            return isPalindrome(num); 
        }
    }
}

int main() {
    cout << "What do you want to check for palindrom, w for word and i for integer: ";
    char c;
    Here:
    cin >> c;
    if(c=='w') {
        string str;
        cout << "Enter a word you want to check for palindrome: ";
        cin >> str;
        if(isPalindrome(str, str.size()-1)) 
            cout << "Your word is palindrome!";
        else 
            cout << "Your word is not palindrome.";
    }
    else if(c=='i') {
        int num;
        cout << "Enter a number you want to check for palindrome: ";
        cin >> num;
         if(isPalindrome(num)) 
            cout << "Your number is palindrome!";
        else 
            cout << "Your number is not palindrome.";
    }
    else {
        cout << "Incorrect input, try again: ";
        goto Here;
    }
    return 0;
}