#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrome(const string &str, unsigned int start, unsigned int end)
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
    if (num < 0)
        return false;

    if (num >= 0 && num <= 9)
        return true;

    int digits = static_cast<int>(log10(num)) + 1;
    int divisor = 1;

    for (int i = 0; i < digits - 1; ++i)
    {
        divisor *= 10;
    }

    while (num != 0)
    {
        int firstDigit = num / divisor;
        int lastDigit = num % 10;

        if (firstDigit != lastDigit)
        {
            return false;
        }

        num = (num % divisor) / 10;
        divisor /= 100;
    }

    return true;
}

int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;

    if (isPalindrome(word, 0, static_cast<unsigned int>(word.length()) - 1))
    {
        cout << "This word is a palindrome!" << endl;
    }
    else
    {
        cout << "This word is not a palindrome!" << endl;
    }

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isPalindrome(num))
    {
        cout << "This number is a palindrome!" << endl;
    }
    else
    {
        cout << "This number is not a palindrome!" << endl;
    }

    return 0;
}