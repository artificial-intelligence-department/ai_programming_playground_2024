#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter two similar integers:";
    std::cin >> n >> m;

    //Calculating
    int res1, res2, res3;
    res1 = n++ - m;
    res2 = m-- > n;
    res3 = n-- > m;

    //Printing our results
    std::cout << "1) n++ - m: " << res1 << std::endl;
    std::cout << "2) m-- > n: " << res2 << std::endl;
    std::cout << "3) n-- > m: " << res3 << std::endl; 

    return 0;
}