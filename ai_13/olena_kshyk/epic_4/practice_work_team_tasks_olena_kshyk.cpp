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

bool isPalindrome(int number)
{
    int reversed = 0;
    int copy = number;
    while (number > 0)
    {
        int x = number % 10;
        reversed = reversed * 10 + x;
        number /= 10;
    }
    return copy == reversed;
}

int main()
{
    string str;
    cout << "Enter a word: ";
    cin >> str;
    cout << "This word is palindrome: " << isPalindrome(str, 0, str.size() - 1) << endl;

    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "This number is palindrome: " << isPalindrome(n) << endl;

    return 0;
}
