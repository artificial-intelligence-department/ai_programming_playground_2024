#include<iostream>
#include<cmath>
using namespace std;

double exect_sum(double x)
{
    double sum;
    sum = -log(1 - 2*x*cos(M_PI/3) + pow(x, 2)) / 2;
    return sum;
}

double n_sum(double x, int n)
{
    double sum = 0.0;
    for (double i = 1; i <= n; i++)
    {
       sum += pow(x, i) * cos(M_PI * i / 3) / i;
    }
    return sum;
}

double epsilon_sum (double x, double e)
{
    double sum = 0.0;
    int i = 1;

    while (abs( pow(x, i) * cos(M_PI * i / 3) / i ) > e)
    {
        sum += pow(x, i) * cos(M_PI * i / 3) / i;
        i++;
    }
    return sum;
}


int main()
{
    int k = 10;
    int n = 35;
    double e = 0.0001; 

    double a = 0.1, b = 0.8;
    double step = (b - a) / k;

    for (double i = a; i <= b; i+=step)
    {
        printf("X = %.5lf\n", i);
        printf("Exect sum: %.10lf\n", exect_sum(i));
        printf("N sum: %.10lf\n", n_sum(i, n));
        printf("Epsilon sum: %.10lf\n\n", epsilon_sum(i, e));
    }

    return 0;
}