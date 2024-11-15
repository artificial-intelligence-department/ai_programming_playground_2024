#include <iostream>

int main()
{
    size_t n;
    int a,b,c;
    int offset = 0;
    int* r;
    std::cin >> n;
    r = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> r[i];
    }
    std::cin >> a >> b >> c;

    for (size_t i = 0; i < n; i++)
    {
        if (r[i] == a || r[i] == b || r[i] == c)
        {
            offset++;
            continue;
        }
        r[i-offset] = r[i];
    }
    if (n <= offset) // edge case
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    n -= offset+1;
    for (size_t i = 0; i < n; i++)
    {
        r[i] += r[i+1];
    }
    std::cout << n << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << r[i] << " ";
    }
}