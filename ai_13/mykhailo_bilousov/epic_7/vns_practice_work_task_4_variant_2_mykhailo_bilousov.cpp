#include <cmath>
#include <iostream>

int main()
{
    std::cout << "\tx\ty" << std::endl;
    for(double x = -4; x <= 4; x += 0.5)
    {
        std::cout << "\t" << x << "\t" << 2*x*x-5*x-8 << std::endl;
    }
}