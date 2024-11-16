#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

const double n = 10;
const double e = 0.0001;
const int k = 10;
const double a = 0.1;
const double b = 0.8;

double funcmain(double x)
{
    double return_func_main;
    return_func_main = x * atan(x) - log(sqrt(1.0 + pow(x, 2.0)));
    return return_func_main;
}

double sumN(double x, double n)
{
    double sum_n;
    for (int i = 1; i <= n; i++)
    {
        sum_n += pow(-1.0, i+1.0) * (pow(x, 2.0*i)/(2.0*i*(2.0*i - 1)));
    }
    return sum_n;
}

double sumE(double x, double e)
{
    double sum_e;
    double a_n;
    bool checker = true;
    int i = 1;
    while (checker)
    {
        a_n = pow(-1.0, i+1.0) * (pow(x, 2.0*i)/(2.0*i*(2.0*i - 1)));
        if (a_n > e)
        {
            checker = true;
            sum_e += a_n;
            i++;
        }
        else{
            checker = false;
        }
    }
    return sum_e;
}


int main()
{
    for (double x = a; x <= b; x += ((b-a)/k))
    {    
        cout << "X = " << x << " SN = " << sumN(x, n) << " SE = " << sumE(x, e) << " Y = " << funcmain(x) << "\n";
    }
}

