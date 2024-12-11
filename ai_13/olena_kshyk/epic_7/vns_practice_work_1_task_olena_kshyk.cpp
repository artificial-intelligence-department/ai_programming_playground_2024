#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double m = 0.7, x = 1.77, a = 0.5, b = 1.08;

    double Z = sin(x) / sqrt(1 + m * m * m * pow(sin(x), 2)) - m * x * log(m * x);
    double S = pow(exp(1), -a * x) * sqrt(x + 1) + pow(exp(1), b * x) * sqrt(abs(x - 3));

    cout << "Z = " << Z << endl;
    cout << "S = " << S << endl;

    return 0;
}