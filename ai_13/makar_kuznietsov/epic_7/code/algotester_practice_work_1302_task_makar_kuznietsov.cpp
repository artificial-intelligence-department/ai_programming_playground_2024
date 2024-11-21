#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            if (i == 0)
            {
                std::cout << 1;
            }
            else
            {
                std::cout << 0;
            }
        }
        else
        {
            std::cout << s[i];
        }
    }
    std::cout << " ";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            std::cout << 9;
        }
        else
        {
            std::cout << s[i];
        }
    }
}
