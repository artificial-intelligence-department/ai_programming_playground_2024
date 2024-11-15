#include <cctype>
#include <iostream>
#include <string>

bool isPalindrom(std::string &str);
bool isPalindrom(int n);

int main()
{
    std::string a;
    int n;
    std::cout << "enter string: ";
    std::cin >> a;
    std::cout << "enter integer: ";
    std::cin >> n;
    std::cout << isPalindrom(a) << '\n';
    std::cout << isPalindrom(n) << '\n';
    return 0;
}

bool isPalindrom(std::string &str)
{
    if (str.length() <= 1)
    {
        return true;
    }
    else if (str.back() == str.front())
    {
        std::string temp = str.substr(1, str.length() - 2);
        return isPalindrom(temp);
    }
    else
    {
        return false;
    }
}

bool isPalindrom(int n)
{
    int reverse = 0;
    int temp = n;
    while (temp != 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse == n);
}
