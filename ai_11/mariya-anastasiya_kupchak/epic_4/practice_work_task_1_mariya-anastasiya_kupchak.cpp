#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) 
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
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1);
}

int main() 
{
    string word;
    cout << "Введіть слово або фразу для перевірки (без пробілів): ";
    cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) 
    {
        cout << "Рядок " << word << " є паліндромом." << endl;
    } 
    else 
    {
        cout << "Рядок " << word << " не є паліндромом." << endl;
    }

    int number;
    cout << "Введіть ціле число для перевірки: ";
    cin >> number;

    if (isPalindrome(number)) 
    {
        cout << "Число " << number << " є паліндромом." << endl;
    } 
    else 
    {
        cout << "Число " << number << " не є паліндромом." << endl;
    }

    return 0;

}