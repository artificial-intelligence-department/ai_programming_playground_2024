#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double P , K;
    double m = 2.1 , t = 1.02 , c = -1;

    P = cbrt(m * tan(t) + fabs(c * sin(t)));

    K = pow(cos(t), 2) - m / cbrt(fabs(m*m - t*t));

    cout << "P = " << P << endl;
    cout << "K = " << K << endl;

    return 0;
}