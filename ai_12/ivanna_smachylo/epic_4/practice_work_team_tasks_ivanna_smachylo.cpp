#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
    if(start >= end) return true;
    if(str[start] != str[end]) return false;
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int k)
{
    if(k < 0) return false;

    int real = k;
    int reversed = 0;

    while(k > 0)
    {
        int num = k % 10;
        reversed = reversed * 10 + num;
        k /= 10;
    }

    return real == reversed;
}

int main()
{
    string str;

    int k;
    cout << "Input a string: ";
    getline(cin, str);
    cout << "\n";

    cout << "Input integer value: ";
    cin >> k;
    cout << "\n";

    cout << "String is palindrome: " << (isPalindrome(str, 0, str.length() - 1) ? "Yes!" : "No!") << "\n";
    cout << "Integer value is palindrome: " << (isPalindrome(k) ? "Yes!" : "No!") << "\n";
}