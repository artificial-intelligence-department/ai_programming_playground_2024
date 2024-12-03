#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "y = |x - 2| + |y + 1|" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    for(double x = -4; x <= 4; x += 0.5)
    {
        double y = fabs(x -  2) + fabs(x + 1);
        std::cout << std::setw(1) << "x: " << std::setw(4) << x << std::setw(10) << "y: " << std::setw(1) << y << std::endl;
    }


    std::cout << "--------------------------------------" << std::endl;

    
    return 0;
}