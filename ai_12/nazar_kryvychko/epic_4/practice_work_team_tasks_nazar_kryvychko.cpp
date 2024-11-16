#include<iostream>
#include<cmath>
// level
// eve
// v

bool isPalindrome(const std::string& str, int start, int end)
{
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

// 34
// log10(120) = (int)2.xxxx + 1;

int numDigits(unsigned int n)
{
    return n == 0 ? 1 : (int)log10(n) + 1;
}

bool isPalindromeH(int num, int digits)
{
    if(num < 10) return true; 

    int firstDigit = num / (int)pow(10, digits - 1);
    int lastDigit = num % 10;
    // 8090 -> 
    // firstDigit = num / (int)10*3 -> 8
    // lastDigit = 8090 % 10 -> 809.[0] -< 0

    if (firstDigit != lastDigit) return false; 

    num = (num % (int)pow(10,digits-1)) / 10;
    return isPalindromeH(num,digits-2);
}

bool isPalindrome(unsigned int num)
{
    return isPalindromeH(num,numDigits(num));
}

int main()
{
    std::string palindrome = "level", notPalindrome = "strike";
    unsigned int numP = 13031,numNP = 1902;

    std::cout << std::boolalpha;
    std::cout << "Is Palindrome: " << palindrome << " -> " << isPalindrome(palindrome,0,palindrome.size()-1) ? "Yes" : "No";
    std::cout << std::endl;
    std::cout << "Is Palindrome: " << notPalindrome << " -> " << isPalindrome(notPalindrome,0,notPalindrome.size()-1) ? "Yes" : "No";
    std::cout << std::endl;
    std::cout << "Is Palindrome: " << numP << " -> " << isPalindrome(numP) ? "Yes" : "No";
    std::cout << std::endl;
    std::cout << "Is Palindrome: " << numNP << " -> " << isPalindrome(numNP) ? "Yes" : "No";
    return 0;
}