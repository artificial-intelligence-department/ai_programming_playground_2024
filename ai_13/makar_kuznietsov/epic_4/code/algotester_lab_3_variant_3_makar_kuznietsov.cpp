#include <iostream>
#include <string>
int main()
{
    std::string s;
    std::cin >> s;
    int i = 0;
    int count = 1;
    while (s[i])
    {
        if (s[i] == s[i + 1])
        {
            count++;
        }
        else
        {
            if (count == 1)
            {
                std::cout << s[i];
            }
            else
            {
                std::cout << s[i] << count;
            }
            count = 1;
        }
        i++;
    }
    return 0;
}
