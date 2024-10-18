#include <iostream>
#include <cmath>
using namespace std;

double byF(double x)
{
    return (((1 + pow(x, 2)) * atan(x) - x) / 2); // ( (1 + x^2) * arctgx - x ) / 2
}

double rowX(double x, double k)
{
    return pow(-1, k + 1) * pow(x, 2 * k + 1) / (4 * pow(k, 2) - 1); // (-1)^(n+1) * x^(2n+1) / (4n^2 -1)
}

double byN(double x, double n)
{
    if (n == 1)
        return rowX(x, n);
    return (rowX(x, n) + byN(x, n - 1));
}

double byE(double x, double e, int k)
{
    double row = rowX(x, k);
    if (row > e)
        return row + byE(x, e, k + 1);
    return row;
}

int main()
{
    double a = 0.1, b = 1.0, e = 0.0001, k = 10.0, n = 30, s = (b - a) / k;

    for (double x = a; x <= b; x += s)
    {
        cout << "X=" << x << "\tSN=" << byN(x, n) << "\tSE=" << byE(x, e, 1) << "\tY=" << byF(x) << "\n\n";
    }

    return 0;
}