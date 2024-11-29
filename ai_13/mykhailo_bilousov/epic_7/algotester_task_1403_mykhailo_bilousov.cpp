// 1403 https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40672
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

int main()
{
    int n, x;
    std::cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    std::cin >> x;
    std::sort(a, a+n, [](int a, int b) { return a > b; });
    int sum = std::accumulate(a, a+n, 0);
    int i = n-1;
    while (sum >= x + a[i])
    {
        sum -= a[i];
        i--;
    }
    std::cout << std::fixed << std::setprecision(4) << (double)sum / (i + 1);
}