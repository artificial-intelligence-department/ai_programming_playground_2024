#include <cmath>
#include <iostream>

int main()
{
    double y, z;
    for(double x = 1; x <= 2; x += 0.2)
    {
        for(double b = 2; b <= 8; b += 2)
        {
            z = sqrt(4*b+x*x)/2;
            y = exp(x/2)*pow(b,x)*(cos(z)+sin(z));
            std::cout
                << "x = " << x << std::endl
                << "b = " << b << std::endl
                << "z = " << z << std::endl
                << "y = " << y << std::endl
                << "----" << std::endl;
        }
    }
}