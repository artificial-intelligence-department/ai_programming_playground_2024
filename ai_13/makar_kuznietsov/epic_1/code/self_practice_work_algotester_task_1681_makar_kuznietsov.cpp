#include <cstdlib>
#include <iostream>
int main()
{
    int n;
    std::cin >> n;
    int x[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (x[i + 1] - x[i] < 2)
        {
            std::cout << "NO";
            exit(0);
        }
    }
    std::cout << "YES";
}
