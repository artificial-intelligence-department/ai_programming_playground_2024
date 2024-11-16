#include <iostream>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;
    int x, y;
    std::cin >> x >> y;
    int x_step = 0, y_step = 0;
    
    for(char chr: str)
    {
        if(chr == 'R')
            x_step++;
        else if(chr == 'U')
            y_step++;
    }
    if ((x_step >= x) && (y_step >= y))
        std::cout << "YES";
    else
        std::cout << "NO";
    
    
    return 0;
}