#include <cmath>
#include <cstdlib>
#include <iostream>
int main()
{
    double a = -2;
    double b = -0.1;
    double k = 10;
    double eps = 0.0001;
    for (double x = a; x <= b; x += (b - a) / k)
    {
        double actRes = std::log(1 / (2 + (2 * x) + (x * x)));
        double arifRes = 0;
        for (int n = 1; n < 40; n++)
        {
            arifRes += std::pow(-1, n) * (pow(1 + x, 2 * n) / n);
        }
        double epsRes = 0;
        int i = 1;
        while (std::abs(actRes - epsRes) > eps)
        {
            epsRes += std::pow(-1, i) * (pow(1 + x, 2 * i) / i);
            i++;
        }
        std::cout << "\nX = " << x << '\n';
        std::cout << "Y = " << actRes << '\n';
        std::cout << "SN = " << arifRes << '\n';
        std::cout << "SE = " << epsRes << '\n';
    }
}
