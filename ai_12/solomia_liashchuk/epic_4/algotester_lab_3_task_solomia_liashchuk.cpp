#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    
    int counter = 1; 
    int n = str.length(); 
    
    for (int i = 0; i < n; i++)
    {
        if (i + 1 < n && str[i] == str[i + 1]) 
        {
            counter++;
        } else 
        {
            std::cout << str[i];
            if (counter > 1) 
            {
                std::cout << counter;
            }
            counter = 1;
        }
    }
    
    return 0;
}

