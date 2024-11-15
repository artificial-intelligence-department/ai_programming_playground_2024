#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string &str, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return is_palindrome(str, start + 1, end - 1);
}

bool is_palindrome(int number)
{
    int original = number;
    int reversed = 0;
    if (number < 0)
    {
        return false;
    }
    while (number > 0)
    {
        int new_number = number % 10;
        reversed = reversed * 10 + new_number;
        number /= 10;
    }
    return original == reversed;
}

int main()
{
    string str;
    cout << "\nEnter a word: ";
    cin >> str;

    if (is_palindrome(str, 0, str.length() - 1))
    {
        cout << "Your word is a palindrome";
    }
    else
    {
        cout << "Your word is not a palindrome";
    }

    int number;
    cout << "\n Enter a number: ";
    cin >> number;
    if (is_palindrome(number))
    {
        cout << "Your number is a palindrome";
    }
    else
    {
        cout << "Your number is not a palindrome";
    }

    return 0;
}