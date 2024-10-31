#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(const string &str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (str[start] == str[end])
    {
        return isPalindrome(str, start + 1, end - 1);
    }
    return false;
}

bool isPalindrome(int number)
{
    if (number < 0)
        return false;

    int count = 1;
    while (number >= pow(10, count))
    {
        count++;
    }
    for (int i = 1; i < count / 2; i++)
    {
        if (number % (int)pow(10, i) != number / (int)pow(10, count - i)){
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "HiiH";
    cout << isPalindrome(str,0,str.length()-1) << endl;
    cout << isPalindrome(14141) << endl;
}