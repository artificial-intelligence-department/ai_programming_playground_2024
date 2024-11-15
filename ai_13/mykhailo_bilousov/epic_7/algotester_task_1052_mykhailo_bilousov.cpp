// 1052 https://algotester.com/uk/ArchiveProblem/DisplayWithEditor/40573
#include <iostream>

int main()
{
    int n, k;
    std::cin >> n >> k;
    if (k > (n-1)/2)
    {
        std::cout << "-1";
    }
    else
    {
        for(int i = 2; i <= 2*k; i += 2)
        {
            std::cout << i << " " << i-1 << " ";
        }
        for(int i = 2*k+1; i <= n; i++)
        {
            std::cout << i << " ";
        }
    }
}