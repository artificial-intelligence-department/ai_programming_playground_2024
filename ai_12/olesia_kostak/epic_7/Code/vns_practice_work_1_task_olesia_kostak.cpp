#include <iostream>
#include <cmath>
//V5

int main()
{
    double a = -0.5, b = 1.7, t = 0.44;

    double s = b * sin(a * pow(t, 2) * cos(2 * t)) - 1;

    double y = exp(-b * t)*sin(a * t + b) - sqrt(fabs(b * t + a));  

    std::cout << "Calculated y: " << y << std::endl << "Calculated s: " << s << std::endl;
    
    return 0;
}