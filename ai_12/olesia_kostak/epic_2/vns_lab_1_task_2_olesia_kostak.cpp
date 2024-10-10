#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter two similar integers:";
    std::cin >> n >> m;

    //Printing our results
    std::cout << (n ++ -m) << std::endl;
    std::cout << (m-- > n) << std::endl;
    std::cout << (n-- > m) << std::endl;

    return 0;
}