#include <cstdlib>
#include <iostream>
int main()
{
    int n, t;
    std::cin >> n >> t;
    int c[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    int time = 0;
    for (int i = 0; i < n - 1; i++)
    {
        time += (abs(c[i] - c[i + 1]) * t);
    }
    std::cout << time;
}
