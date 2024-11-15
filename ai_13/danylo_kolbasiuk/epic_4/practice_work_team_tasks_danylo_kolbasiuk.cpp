#include <iostream>
#include <string>

bool isPalindrome(const std::string& str, int start, int end)
{
    bool checker=true;
    if (start<end)
    {
        if (str[start]==str[end])
        {
            checker=isPalindrome(str, start+1, end-1);
        }
        else
        {
            checker=false;    
        }
    }
    return checker;
}
bool isPalindrome(int num)
{
    int uno=num;
    int onu=0;
    while (num>0)
    {
        onu=onu*10+num%10;
        num=num/10;
    }
    return uno==onu;
}
int main()
{
    std::string input1;
    int input2;
    std::cout << "Input a string: ";
    std::cin >> input1;
    if(isPalindrome(input1, 0, input1.length()-1))
    {
        std::cout << "The string is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The string is not a palindrome." << std::endl;
    }
    std::cout << "Now input a whole number: ";
    std::cin >> input2;
    if(input2<0)
    {
        std::cout << "The number is negative, therefore it's not a palindrome.";
    }
    else if(isPalindrome(input2))
    {
        std::cout << "The number is a palindrome.";
    }
    else
    {
        std::cout << "The number is not a palindrome.";
    }
}