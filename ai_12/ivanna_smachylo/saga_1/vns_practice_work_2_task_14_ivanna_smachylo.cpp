#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>

using namespace std;

void calculate(double *x, int size, double a)
{
    cout << fixed << setprecision(4);
    int i = 0;
    do 
    {
        if(*(x + i) == 0)
        {
            cout << "z is undefined for x = " << *(x + i) << " (division by 0)" << "\n";
        }
        else
        {
            double ln = log(abs(*(x + i) + pow(2, 3)));
            double z = (pow(a, *(x + i)) * ln) / *(x + i) + 1;
            cout << "x for x: " << *(x + i) << " is " << z << "\n";
        }
        i++;
    }
    while (i < size);
}

int main()
{
    double a = 2.4;
    int k = 0;
    double x[13]; //значення від -3 до 3
    for(double i = -3; i <= 3; i += 0.5)
    {
        *(x + k) = i;
        k++;
    }

    calculate(x, k, a);

    return 0;
}