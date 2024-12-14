#include <iostream>
#include <string>
#include <cmath>

bool isPalindrome(const std::string &str, int start, int end)
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

bool isPalindrome(int num)
{
    std::string str = std::to_string(num);
    return isPalindrome(str, 0, str.length() - 1);
}

int main()
{
    std::string testString;
    std::cout << "Enter a string to check if it's a palindrome: ";
    std::cin >> testString;

    if (isPalindrome(testString, 0, testString.length() - 1))
    {
        std::cout << "The string \"" << testString << "\" is a palindrome.\n";
    }
    else
    {
        std::cout << "The string \"" << testString << "\" is not a palindrome.\n";
    }

    int testNumber;
    std::cout << "Enter a number to check if it's a palindrome: ";
    std::cin >> testNumber;

    if (isPalindrome(testNumber))
    {
        std::cout << "The number " << testNumber << " is a palindrome.\n";
    }
    else
    {
        std::cout << "The number " << testNumber << " is not a palindrome.\n";
    }

    return 0;
}
