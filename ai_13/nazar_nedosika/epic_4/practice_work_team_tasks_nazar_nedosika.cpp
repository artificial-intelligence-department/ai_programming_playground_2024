#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num)
{
    if (num < 0)
        return false;

    int original = num;
    int reversed = 0;

    while (num > 0)
    {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    return original == reversed;
}

int main()
{
    string input1;
    int input2;

    cout << "Введіть слово: ";
    cin >> input1;
    
    if (isPalindrome(input1, 0, input1.length() - 1))
    {
        cout << "Це слово є паліндромом" << endl;
    }
    else
    {
        cout << "Це слово не є паліндромом" << endl;
    }

    cout << "Введіть число: ";
    cin >> input2;

    if (isPalindrome(input2))
    {
        cout << "Це число паліндром" << endl;
    }
    else
    {
        cout << "Це число не є паліндромом" << endl;
    }

    return 0;
}