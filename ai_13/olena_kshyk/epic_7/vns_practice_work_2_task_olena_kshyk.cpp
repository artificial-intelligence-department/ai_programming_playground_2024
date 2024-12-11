#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    double h = 0.5;
    for (double x = 1.0; x <= 4.0; x += h)
    {
        double z = abs(x) + pow(x, 3);
        double y = z * sin(pow(2 + x, 2)) / (2 + x);
        printf("x = %.1lf \t z = %.3lf \t y = %lf \n", x, z, y);
    }

    return 0;
}