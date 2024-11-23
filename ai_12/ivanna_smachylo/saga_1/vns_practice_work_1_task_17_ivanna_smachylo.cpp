#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main()
{
    float a = 3.2, b = 17.5, x = -4.8; //надала значення a,b,x через float, бо числа з плаваючою крапкою

    double denominator = pow(sin(x/a), 2); //використала double(для чисел з плаваючою крапкою), pow-для степеня
    double Y = (pow(b, 3) * pow(tan(x), 2)) - a / denominator;

    double e = exp(-(sqrt(3))); //e=exp, корінь=sqrt
    double Z = a * e * cos(b*x/a);

    cout << "Result Y = " << Y << "\n";
    cout << "Result Z = " << Z;

    return 0;
}