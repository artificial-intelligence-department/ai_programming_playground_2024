#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string& text, int& start, int end){
    
    if(start >= end)
    return true;

    if (text[start] != text[end])
    return false;

    return isPalindrome(text, ++start, --end);
    
}

bool isPalindrome(int& number) {

    string text = to_string(number);

    int start = 0;
    int end = text.length() - 1;

    return isPalindrome (text, start, end);
}

int main () {

string text1;
getline(cin, text1);

int start = 0;
int end = text1.length() - 1; 

if(isPalindrome(text1, start, end)) {
    cout << "string \"" << text1 << "\" is a palindrome\n";
}
else {
    cout << "string \"" << text1 << "\" is NOT a palindrome\n";
}

int text2;
cin >> text2;

(isPalindrome(text2)) ? cout << "string \"" << text2 << "\" is a palindrome\n" : cout << "string " << text2 << " is NOT a palindrome\n";

return 0;
}

