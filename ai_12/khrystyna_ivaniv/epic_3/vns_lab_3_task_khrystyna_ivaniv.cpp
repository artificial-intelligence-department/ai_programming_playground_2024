#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double ε = 0.0001;
int n = 25;

int factorial_func(int number)
{
    int factorial = 1;

    for (int i = 1; i <= number; i++)
    {
        factorial *= i;
    }
    return factorial;
}

double SN(double x)
{
    long double sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += (cos(i * M_PI / 4) * x / factorial_func(i)) * pow(x, i);
    }
    return sum;
}

double SE(double x)
{
    long double sum = 1;
    long double new_sum;
    int i = 1;
    do
    {
        new_sum = sum;
        sum += (cos(i * M_PI / 4) * x / factorial_func(i)) * pow(x, i);
        i++;
    } while (abs(new_sum - sum) > ε);
    return sum;
}

double Y(double x)
{
    return pow(M_E, cos(M_PI / 4) * x) * cos(x * M_PI / 4);
}

int main()
{

    double a = 0.1, b = 1.0;
    int k = 10;
    double step = (b - a) / k;
    cout << fixed << setprecision(10);
    for (double x = a; x <= b; x += step)
    {
        cout << "X = " << x << "; SN = " << SN(x) << "; SE = " << SE(x) << "; Y = " << Y(x) << endl;
    }
    return 0;
}