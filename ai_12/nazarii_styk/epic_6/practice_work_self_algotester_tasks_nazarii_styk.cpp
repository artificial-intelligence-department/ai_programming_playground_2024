#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;

    if((m * n) % 2 == 0)
    {
        std::cout << "Dragon" << std::endl;
    }
    else
    {
        std::cout << "Imp" << std::endl;
    }

    return 0;
}
