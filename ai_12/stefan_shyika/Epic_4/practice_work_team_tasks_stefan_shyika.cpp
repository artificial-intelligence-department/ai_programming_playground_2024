#include <iostream>
#include<cmath>

using namespace std;

bool isPalindrome(const string& s, int start, int end){
    if(start >= end) return true;
    if(s[start] != s[end]) return false;
    return isPalindrome(s, start+1, end-1);
}

bool isPalindrome(int n) {
    if (n < 0) return false;

    int original = n; 
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed; 
}

int main(){
    string s;
    int n;
    cout << "Input a string: ";
    getline(cin, s);
    cout << endl;
    cout << "Input an integer: ";
    cin >> n;
    cout << endl;

    cout << "String is palindrome: " << (isPalindrome(s, 0, s.length()-1) ? "Yes" : "No") << endl;
    cout << "Integer is palindrome: " << (isPalindrome(n) ? "Yes" : "No") << endl;
}