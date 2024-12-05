#include <cmath>
#include <iostream>
int main()
{
    int n, k;
    std::cin >> n >> k;
    int count = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if (temp > k)
        {
            count++;
        }
    }
    std::cout << count;
}
