#include <iostream>

int main()
{
    long long H, M;
    std::cin >> H >> M;

    long long h1, m1, h2, m2, h3, m3;
    std::cin >> h1 >> m1 >> h2 >> m2 >> h3 >> m3;


    if ((h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0)) 
    {
       std::cout << "NO" << std::endl;
        return 0;
    }

    H -= (h1 + h2 + h3);
    M -= (m1 + m2 + m3);

    if (H > 0 && M > 0) 
    {
        std::cout << "YES" << std::endl;
    } 
    else
    {
        std::cout << "NO" << std::endl;
    }

    return 0;
}