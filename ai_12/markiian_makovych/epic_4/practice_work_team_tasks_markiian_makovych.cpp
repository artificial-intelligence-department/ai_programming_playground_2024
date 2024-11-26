#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPalindrom(string str, int start, int end)
{

    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
        return false;

    return isPalindrom(str, start + 1, end - 1);
}

int getFirstDigit(int number)
{

    while (number >= 10)
    {
        number /= 10;
    }

    return number;
}
bool isPalindrom(int num)
{
    bool isPal = true;
    int start = getFirstDigit(num);
    int end = num % 10;

    if (static_cast<int>(to_string(num).length()) <= 1)
    {
        return true;
    }
    if (start != end)
    {
        return false;
    }

    if (start == end)
    {
        num /= 10;
        num %= static_cast<int>(pow(10, static_cast<int>(log10(num))));
        return isPalindrom(num);
    }
    return true;
}

int main()
{
    if (isPalindrom("aavvaavvaa", 0, 9) == 1)
    {
        cout << "(aavvaavvaa) is a palindrom" << endl;
    }

    if (isPalindrom(12321) == 1)
    {
        cout << "(12321) is a palindrom" << endl;
    }

    return 0;
}