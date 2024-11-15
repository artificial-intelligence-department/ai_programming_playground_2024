#include <iostream>
#include <string>

bool isPalindrome(const std::string& str, int start, int end);
bool isPalindrome(unsigned long long number);

int main()
{
    std::string S;
    std::cin >> S;
    std::cout << isPalindrome(S,0,S.size()-1) << std::endl;

    unsigned long long n;
    std::cin >> n;
    std::cout << isPalindrome(n) << std::endl;
    std::cout << n+1 << " " << isPalindrome(n+1);
}

bool isPalindrome(const std::string& str, int start, int end)
{
    if (end < start) throw std::invalid_argument("End cannot be smaller than start");
    if (end - start < 1) return true; // base case
    if (end - start == 1) return str[start] == str[end]; // base case
    return str[start] == str[end] && isPalindrome(str,start+1,end-1);
}

bool isPalindrome(unsigned long long number)
{
    unsigned long long reverse = 0, temp = number;
    while (temp > 0)
    {
        reverse *= 10;
        reverse += temp % 10;
        temp /= 10;
    }
    return (reverse == number);
}