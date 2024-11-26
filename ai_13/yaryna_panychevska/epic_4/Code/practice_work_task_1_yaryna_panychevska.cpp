#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string& word, int start, int end)
{
    if (start == end)
    {
        return true;
    }

    if (word[start] != word[end])
    {
        return false;
    }
    return isPalindrome(word, start + 1, end - 1);
}

bool isPalindrome(int num)
{
    int original = num;
    int rev_num = 0;
    if (num < 0)
    {
        return false;
    }

    do
    {
        int lastDigit = num % 10;
        rev_num = rev_num * 10 + lastDigit;
        num = num / 10;
    } while (num > 0);
    return original == rev_num;
}
    
int main()
{
    string word;
    int num;
    int input;
    cout << "Int - [0]\tStr - [1]\nEnter a type of data you want to work with:";
    cin >> input;
    if (input == 0)
    {
        cout << "Enter a number: ";
        cin >> num;
        if (isPalindrome(num))
        {
            cout << "This number is palindrome.";
        }
        else {
            cout << "This number is not palindrome.";
        }
    }
    if (input == 1)
    {
        cout << "Enter a word: ";
        cin >> word;
        if (isPalindrome(word, 0, word.size() - 1))
        {
            cout << "This word is palindrome.";
        }
        else {
            cout << "This word is not palindrome.";
        }
    }
    return 0;
}