#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double m = 0.7;
    double x = 1.77;
    double a = 0.5;
    double b = 1.08;
    // Обчислення для Z
    double numeratorZ = sin(x);
    double denominatorZ = sqrt(1 + pow(m, 3)*pow(sin(x), 2));
    double resultZ = numeratorZ / denominatorZ - m*x*log(m*x);
    // Обчислення для S
    double firstPartS = exp(-a * x) * sqrt(x+1);
    double secondPartS = exp(b*x) * sqrt(fabs(x-3));
    double resultS = firstPartS + secondPartS;

    cout << resultZ << endl;
    cout << resultS << endl;

    return 0;
}