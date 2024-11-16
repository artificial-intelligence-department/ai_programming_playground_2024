#include <iostream>

using namespace std;

bool isPalindrome(int num);

bool isPalindrome(const string& str, int start, int end);

int main()
{
    int ans;
    cout << "for exit type 0, for string type 1, for integer type 2\n";     
    cin >> ans; 
    while (ans!=0)
    {
        if (ans == 1)
        {     
            string s;
            cout << "Input a string: \n";
            cin.ignore();
            getline(cin, s);
            bool res = isPalindrome(s, 0, s.length() - 1);
            if (res)
            {
                cout << "This string is palindrome\n";
            }
            else
            {
                cout << "This string is not palindrome\n";
            }
        }
        else if (ans == 2)
        {
            cout << "Input a number: \n";
            int number;
            cin >> number;
            if (isPalindrome(number))
            {
                cout << "This number is palindrome\n";
            }
            else
            {
                cout << "This number is not palindrome\n";
            }
        } 

        cout << "for exit type 0, for string type 1, for integer type 2\n";     
        cin >> ans; 
    }
}


bool isPalindrome(const string& str, int start, int end)
{
    if (start >= end)
    {
        return 1;
    }
    if (str[start] != str[end])
    {
        return 0;
    }
    return isPalindrome(str,start+1,end-1);
}


bool isPalindrome(int num)
{
    if (num<0)
    {
        return 0;
    }
    int original = num; 
    int reversed = 0;
    int digit;

    while (num != 0) {
        digit = num % 10;
        reversed = reversed * 10 + digit;  
        num /= 10;  
    }
    return original == reversed; 
}