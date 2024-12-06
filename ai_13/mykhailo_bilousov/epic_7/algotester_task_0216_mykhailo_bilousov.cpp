// 0216 https://algotester.com/en/ArchiveProblem/DisplayWithFile/20094
#include <iostream>
#include <iomanip>

int main()
{
    int n, k;
    std::cin >> n >> k;
    if(n == 0 || k == 0) std::cout << "0.000000";
    else std::cout << std::fixed << std::setprecision(6) << 1.0/(n*k);
}