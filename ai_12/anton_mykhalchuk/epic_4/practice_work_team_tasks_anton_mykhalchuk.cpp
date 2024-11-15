#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num)
{
    int original = num, reversedNumber = 0, digit;
    while (num > 0)
    {
        digit = num % 10;
        reversedNumber = reversedNumber * 10 + digit;
        num = (num - digit) / 10;
    }

    return original == reversedNumber;
}

int main()
{

    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1))
    {
        cout << word << " is a palindrome." << endl;
    }
    else
    {
        cout << word << " is not a palindrome." << endl;
    }

    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPalindrome(number))
    {
        cout << number << " is a palindrome." << endl;
    }
    else
    {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}