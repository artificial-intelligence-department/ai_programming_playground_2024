#include <iostream>
#include <cmath>

using namespace std;

int factorialCalc(int number)
{
    int factorial = 1;
    for (int i = 1; i <= number; i++)
    {
        factorial *= i;
    }
    return factorial;
}

double xEquation(double x, int number)
{
    return pow(x, (2 * number + 1));
}

int main()
{
    double a = 0.1, b = 1.0, ε = 0.0001;
    int k = 10; 
    double step = (b - a) / k;

    int n = 20;

    cout << "Розрахунки для x від " << a << " до " << b << " з кроком " << step << endl;

    cout << '\t' << "Обчислення функції" << '\t' << endl;
    for (double x = a; x <= b; x += step)
    {
        double sumN = x; 
        double sumE = x; 
        double term;     

        double y = (exp(x) - exp(-x)) / 2;

        cout.precision(2);
        cout << "X = " << x << " " << '\t';

        for (int i = 1; i <= n; i++)
        {
            term *= (x * x) / ((2 * i) * (2 * i + 1));
            sumN += term;
        }

        cout.precision(17);
        cout << "SN = " << sumN << '\t';

        int i = 1;
        term = xEquation(x, i) / factorialCalc(2 * i + 1);
        while (fabs(term) > ε)
        {
            sumE += term;
            i++;
            term = xEquation(x, i) / factorialCalc(2 * i + 1);
        }

        cout.precision(4);
        cout << "SE = " << fixed << sumE << '\t';

        cout.precision(17);
        cout << fixed << "Y = " << fixed << y << endl;
    }

    return 0;
} 