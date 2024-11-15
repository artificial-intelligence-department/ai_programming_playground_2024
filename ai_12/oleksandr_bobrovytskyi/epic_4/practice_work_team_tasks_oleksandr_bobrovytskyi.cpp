#include<bits\stdc++.h>

using namespace std;

bool IsPalindrome(const string& str, int start, int end)
{    
    if(end <= start )
    {
        return true;
    }

    if(str[start] != str[end - 1])
    {
        return false;
    }

    return IsPalindrome(str, start + 1, end - 1);
}

bool IsPalindrome(const int number)
{
    if(number > 0)
    {
        
        int element, reversed = 0;
        int num = number;
        while(num != 0)
        {
            element = num % 10;
            reversed = reversed * 10 + element;
            num -= element;
            num /= 10;
        }
        return reversed == number;
    }
    return false;
}

int main()
{   
    string str;
    int number;

    cout << "Input your word here : ";
    cin >> str;

    if (IsPalindrome(str, 0, str.length()))
    {
        cout << "Your word is a palindrome" << endl;
    }
    else
    {
        cout << "Your word is not a palindrome" << endl;
    }

    cout << "Input your number here : ";
    cin >> number;

    if (IsPalindrome(number))
    {
        cout << "Your number is a palindrome" << endl;
    }
    else
    {
        cout << "Your number is not a palindrome" << endl;
    }

    return 0;
}