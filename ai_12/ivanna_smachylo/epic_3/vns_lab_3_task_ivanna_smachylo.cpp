#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

long long factorialC(int num)
{
    int factorial = 1;
    for(int i = 1; i <= num; i++)
    {
        factorial *= i;
    }
    return factorial;
}

int main()
{
    double a = 0.1, b = 1.0, ε = 0.0001;
    int f = 10;
    double f1 = (b - a)/f;

    int m = 10;

    cout << "Calculations for x from " << a << " to " << b << " in increments " << f1 << "\n";

    cout << "Computing the function:" << "\n";

    for(double x = a; x <= b; x += f1)
    {
        double sum1 = x;
        double sum2 = x;
        double term;

        double y = (exp(x) + exp(-x)) / 2;

        cout << fixed << setprecision(4);
        cout << "X = " << x << " " << '\t';

        for(int i = 1; i <= m; i++)
        {
            term *= (x * x) / ((2 * i) * (2 * i - 1));
            sum1 += term;
        }

        cout << "Series sum approximation: " << sum1 << '\t';
        cout << "Exact y: " << y << "\n";
    }

    return 0;
}