#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) return true;

    if (str[start] != str[end]) return false;
    
    return isPalindrome(str, start + 1, end - 1); // наступна пара значень (рухаємось від кінців до середини)
}

bool isPalindrome(int number) {

    if (number < 0) return false; // тому що (-) може стояти тільки з лівого боку
    
    int reversed = 0;
    int original = number;

    while (number != 0) {
        int digit = number % 10;
        reversed = reversed * 10 + digit;
        number /= 10;
    }
    return original == reversed;
}

int main() {
    string str;
    int num;

    cout << "Input a string ";
    getline(cin, str);
    cout << "\n";
    cout << "Input a number ";
    cin >> num;
    cout << "\n";

    cout << "Is your string palindrome?: " << (isPalindrome(str, 0, str.length()-1) ? "Yes" : "No") << endl;
    cout << "Is your integer palindrome?: " << (isPalindrome(num) ? "Yes" : "No") << endl;

    return 0;
}
