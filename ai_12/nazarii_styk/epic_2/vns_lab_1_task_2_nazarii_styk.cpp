#include <iostream>

int main()
{
    int m, n;
    std::cin >> m >> n;

    std::cout << "First: " << m + --n << std::endl;
    std::cout << "Second: " << (m++ < ++n) << std::endl;
    std::cout << "Third: " << (n-- < --m) << std::endl;

    return 0;
}