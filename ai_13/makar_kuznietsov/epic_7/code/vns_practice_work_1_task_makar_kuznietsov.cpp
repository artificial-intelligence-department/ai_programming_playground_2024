// variant 18
#include <cmath>
#include <cstdlib>
#include <iostream>
double funcK(double a, double b, double x);
double funcM(double a, double b, double c, double x);
int main()
{
    double a = 10.2;
    double b = 9.3;
    double x = 2.4;
    double c = 0.5;
    std::cout << funcK(a, b, x) << '\n';
    std::cout << funcM(a, b, c, x) << '\n';
}

double funcK(double a, double b, double x)
{
    return log(a + pow(x, 3)) + pow(sin(x / b), 2);
}

double funcM(double a, double b, double c, double x)
{
    return exp(-c * x) * (x + cbrt(x + a)) / (x - sqrt(std::abs(x - b)));
}
