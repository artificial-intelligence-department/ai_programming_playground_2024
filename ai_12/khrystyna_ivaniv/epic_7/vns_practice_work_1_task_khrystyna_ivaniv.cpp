#include <math.h>
#include <iostream>
int main()
{

    float b = 15.5;
    float x = -2.9;
    float a = 1.5;
    double y = pow(cos(pow(x, 3)), 2) - x / (sqrt(pow(a, 2) + pow(b, 2)));
    double P = sqrt(pow(x, 2) + b) - (pow(b, 2) * pow(sin(x + a), 3)) / (x * y);
    std::cout << P;
    return 0;
}
