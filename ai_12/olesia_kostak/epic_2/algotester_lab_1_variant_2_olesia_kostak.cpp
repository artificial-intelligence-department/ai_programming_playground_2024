#include <iostream>
#include <algorithm>

int main()
{
    
    long long h[4];
    long long min_h = 1000000000000LL;
    long long max_h = -1;
    bool result = true;
    
    for (int i = 0; i < 4; i++)
    {
        std::cin >> h[i];
        min_h = std::min(h[i], min_h);
        max_h = std::max(h[i], max_h);
    }
    
    for (int i = 0; i < 4; i++)
    {
        long long d;
        std::cin >> d;
        if (d > h[i])
        {
            std::cout << "ERROR";
            return 0;
        }
        h[i] = h[i] - d;
        min_h = *std::min_element(h, h + 4);
        max_h = *std::max_element(h, h + 4);

        if (max_h >= 2 * min_h)
            result = false;
    }
    

    if ((result == false) || (!(h[0] == h[1] && h[1] == h[2] && h[2] == h[3])))
        {
            std::cout << "NO";
            return 0;
        }
    std::cout << "YES";
    return 0;
}