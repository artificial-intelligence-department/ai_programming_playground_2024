#include <iostream>
#include <string>

using namespace std;

// Рекурсивна функція для перевірки, чи є рядок паліндромом
bool isPalindrome(const string& str, int start, int end) 
{
    // Якщо початок перевищує кінець, рядок є паліндромом
    if (start >= end) 
    {
        return true;
    }
    // Перевірка символів на початку і в кінці
    if (str[start] != str[end]) 
    {
        return false;
    }
    
    return isPalindrome(str, start + 1, end - 1);
}

// Перевантажена функція для перевірки, чи є ціле число паліндромом
bool isPalindrome(int number) 
{
    // Перетворення числа на рядок
    string str = to_string(number);
    return isPalindrome(str, 0, str.length() - 1);
}

int main() 
{
    string testStr;
    cout << "Enter a string: ";
    cin >> testStr;
    if (isPalindrome(testStr, 0, testStr.length() - 1)) 
    {
        cout << "The string is a palindrome." << endl;
    } 
    else 
    {
        cout << "The string is not a palindrome." << endl;
    }

    int testNum;
    cout << "Enter a number: ";
    cin >> testNum;
    if (isPalindrome(testNum)) 
    {
        cout << "The number is a palindrome." << endl;
    } 
    else 
    {
        cout << "The number is NOT a palindrome." << endl;
    }

    return 0;
}