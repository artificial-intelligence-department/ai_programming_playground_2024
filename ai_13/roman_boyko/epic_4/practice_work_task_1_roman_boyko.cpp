#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isPalindrome(string s, int start, int end);
bool isPalindrome(int num, int count);
int count(int num);
int main()
{
    int num = 12329;
    string s = "radar";
    int st = 0;
    int e = s.length() - 1;
    bool k = isPalindrome(s, st, e);
    if (k)
    {
        cout << s << " - is a palindrome!";
    }
    else
    {
        cout << s << " - is not a palindrome!";
    }
    cout << endl;
    int c1 = count(num);
    bool c = isPalindrome(num, c1);
    if (c)
    {
        cout << num << " - is a palindrome!";
    }
    else
    {
        cout << num << " - is not a palindrome!";
    }
}
int count(int num)
{
    int c = 0;
    while (num != 0)
    {
        num /= 10;
        c++;
    }
    return c;
}
bool isPalindrome(string s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (s[start] != s[end])
    {
        return false;
    }
    return isPalindrome(s, start + 1, end - 1);
}
bool isPalindrome(int num, int count)
{
    if (num < 10)
    {
        return true;
    }
    int start = num / (int)pow(10, count - 1);
    int end = num % 10;
    if (start != end)
    {
        return false;
    }
    num = (num % (int)pow(10, count - 1)) / 10;
    return isPalindrome(num, count - 2);
}