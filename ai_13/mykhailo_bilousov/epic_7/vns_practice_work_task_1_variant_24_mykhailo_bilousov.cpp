#include <cmath>
#include <iostream>

int main()
{
    double m = 2.1, t = 1.02, c = -1.0;
    double P = cbrt(m*tan(t)+fabs(c*sin(t)));
    double K = cos(t)*cos(t)-m/cbrt(fabs(m*m-t*t));
    std::cout 
        << "m = " << m << std::endl 
        << "t = " << t << std::endl
        << "c = " << c << std::endl
        << "P = " << P << std::endl
        << "K = " << K << std::endl;
}