#include <iostream>
#include <cmath>

int main()
{
    int n,m, op1;

    std::cout << "Input n,m" <<std::endl;
    std::cin >> n >> m;
    op1 = n++*m;
    std::cout << "1) " << op1 <<std::endl;
    if (n++<m)
        std::cout << "2) True" <<std::endl;
    else
        std::cout << "2) False" <<std::endl;

    if (m-->m)
        std::cout << "3) True" <<std::endl;
    else
        std::cout << "3) False" <<std::endl;

    return 0;     
}
