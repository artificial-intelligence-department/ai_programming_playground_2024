#include <iostream>
#include <string>
#include <cmath>

bool isPalindrome(const std::string& str, int start, int end);
bool isPalindrome(int num);

int main()
{
    std::string str;
    std::cout << "Enter a string to check whether it's a palindrome:" << std::endl;
    std::cin >> str;
    int start = 0, end = str.length() - 1;
    std::cout << (isPalindrome(str, start, end) ? "True": "False") << std::endl;;

    std::cout << "Enter a number to check wether it's a palindrome: " << std::endl;
    int num;
    std::cin >> num;
    std::cout << (isPalindrome(num)? "True": "False") << std::endl;

    return 0;
}

bool isPalindrome(const std::string& str, int start, int end)
{
    if(start < end)
    {
        if (str[start] != str[end])
            return 0;
        return isPalindrome(str, start + 1, end - 1);
    }
    else
        return 1;
}

bool isPalindrome(int num)
{
    if(num < 0)
        return 0;

    int temp = num;
    int reversed = 0;

    while (temp > 0)
        {
            reversed = (temp % 10) + (reversed * 10);
            temp /= 10;
        }
    return reversed == num; 
}


// bool isPalindrome(int num)
// {
//     int temp = num;
//     int lenNum = 0;
//     while(temp != 0)
//     {
//         lenNum++;
//         temp /= 10;
//     }
//     if(num > 0)
//     {
//         if(num % 10 != num / static_cast<int>(pow(10, lenNum - 1)))
//             return 0;

//         return isPalindrome((num % static_cast<int>(pow(10, lenNum - 1))) / 10);
//     }
//     else if (num < 0)
//         return 0;
//     else
//         return 1; 
// }