#include <iostream>
#include <cmath>
using namespace std;

// Функція для обчислення точного значення y = 2(cos^2(x) - 1)
double exactFunction(double x)
{
    return 2 * (pow(cos(x), 2) - 1);
}

// Функція для обчислення значення ряду для заданого числа членів n
double seriesForN(double x, int n)
{
    double sum = 0;
    for (int k = 1; k <= n; k++)
    {
        double An = pow(-1, k) * pow(2 * x, 2 * k) / tgamma(2 * k + 1);
        sum += An;
    }
    return sum;
}

// Функція для обчислення значення ряду для заданої точності e
double seriesForE(double x, double e)
{
    double sum = 0;
    double An;
    int k = 1;
    while (true)
    {
        An = pow(-1, k) * pow(2 * x, 2 * k) / tgamma(2 * k + 1);
        if (abs(An) > e)
        {
            sum += An;
            k++;
        }
        else
        {
            break;
        }
    }
    return sum;
}

int main()
{
    double a = 0.1, b = 1.0;
    int k = 10;
    double step = (b - a) / k;
    int n = 15;
    double e = 0.0001;

    for (double x = a; x <= b; x += step)
    {
        double exact = exactFunction(x);
        double seriesN = seriesForN(x, n);
        double seriesE = seriesForE(x, e);

        cout << "X=" << x << "\tSN=" << seriesN << "\tSE=" << seriesE << "\tY=" << exact << endl;
    }

    return 0;
}
