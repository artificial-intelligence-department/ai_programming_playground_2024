#include <iostream>
#include <cmath>

int main()
{
    double h_x = 0.5;
    double h_a = 0.2;
    double a = -0.5;

    for(double x = 1; x <= 4; x += h_x)
    {
        a += h_a;
        if(x - 1.5 < 0)
            std::cerr << "Square root of a negative number is impossible in school math! )))" << std::endl;
        else
        {
            long double numerator = sqrt(x - 1.5) + pow(x, a);
            long double denominator = cbrt(x - 2); //cube root
            long double z = numerator / denominator;
            std::cout << "For x = " << x << ", a = " << a << std::endl << "Calculated z: " << z << std::endl;
        }
        
    }

    return 0;
}