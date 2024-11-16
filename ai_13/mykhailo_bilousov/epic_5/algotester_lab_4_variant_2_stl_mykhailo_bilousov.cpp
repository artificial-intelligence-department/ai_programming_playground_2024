#include <iostream>
#include <algorithm>

int main()
{
    int n, k;
    std::cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a, a+n);
    n = std::unique(a, a+n) - a;
    k %= n;
    std::rotate(a, a+k, a+n);
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
}