#include <cmath>
#include <cstdarg>
#include <iostream>
#include <vector>

#define sideLen(a, b) sqrt(std::pow(a[0] - b[0], 2) + std::pow(a[1] - b[1], 2))

double square(int a[2], int b[2], int c[2]);
double squaren(int k, ...);

int main()
{
    int a[2] = {3, 5};
    int b[2] = {1, 2};
    int c[2] = {7, 3};
    int i = sqrt(a[1]);
    std::cout << "A(" << a[0] << ";" << a[1] << ")" << '\n';
    std::cout << "B(" << b[0] << ";" << b[1] << ")" << '\n';
    std::cout << "C(" << c[0] << ";" << c[1] << ")" << '\n';
    std::cout << "length of AB = " << sideLen(a, b) << '\n';
    std::cout << "area of ABC = " << square(a, b, c) << '\n';
    double res = squaren(3, 1.0, 2.0, 3.0, 5.0, 1.0, 3.0);
    std::cout << "area of our polygon = " << res;
    return 0;
}

double square(int a[2], int b[2], int c[2])
{
    return 0.5 * ((a[0] * b[1] + b[0] * c[1] + c[0] * a[1]) - (a[1] * b[0] + b[1] * c[0] + c[1] * a[0]));
}
double squaren(int k, ...)
{
    std::vector<double> x_coords, y_coords;
    va_list args;
    va_start(args, k);
    for (int i = 0; i < k; ++i)
    {
        double x = va_arg(args, double);
        double y = va_arg(args, double);
        x_coords.push_back(x);
        y_coords.push_back(y);
    }
    va_end(args);
    double res = 0.0;
    for (int i = 0; i < k; i++)
    {
        int j = (i + 1) % k;
        res += x_coords[i] * y_coords[j] - x_coords[j] * y_coords[i];
    }
    return res / 2;
}
