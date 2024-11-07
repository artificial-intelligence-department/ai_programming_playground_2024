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
    for (int i = 1; i < count / 2 + 1; i++)
    {
        if ((number % (int)pow(10, i))/ (int)pow(10, i-1) 
        != (number / (int)pow(10, count - i)) % 10){
            return false;
        }
    }
    return true;
}

int main()
{
    string str = "HsiiH";
    int number = 122333321;
    cout << "Cheking string \"" + str + "\" on palindrome: " << isPalindrome(str,0,str.length()-1) << endl;
    cout << "Cheking number \"" + to_string(number) + "\" on palindrome: " << isPalindrome(number) << endl;
}