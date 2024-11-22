#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x = 1.23, y = 0.79;

    double denominator = pow(y, 3) + fabs(pow(x, 2) / (y + pow(x, 2 / 3)));

    double a = y + (x / denominator);

    double tangens = pow(tan(x / 2), 2);

    double b = 1 + tangens;

    double *A = &a;

    cout << "a = " << *A << endl;

    cout << "b = " << b << endl;
}