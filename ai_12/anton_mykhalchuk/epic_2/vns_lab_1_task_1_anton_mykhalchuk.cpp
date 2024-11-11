#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float a1, b1, c1, d1, e1, f1, g1, h1, i1;
    double a2, b2, c2, d2, e2, f2, g2, h2, i2;

    a1 = 1000;
    b1 = 0.0001;

    c1 = pow(a1 - b1, 3);
    d1 = pow(a1, 3) - 3 * a1 * pow(b1, 2);
    e1 = pow(b1, 3);
    f1 = 3 * pow(a1, 2) * b1;
    g1 = c1 - d1;
    h1 = e1 - f1;
    i1 = g1 / h1;

    cout << i1 << endl;

    a2 = 1000;
    b2 = 0.0001;

    c2 = pow(a2 - b2, 3);
    d2 = pow(a2, 3) - 3 * a2 * pow(b2, 2);
    e2 = pow(b2, 3);
    f2 = 3 * pow(a2, 2) * b2;
    g2 = c2 - d2;
    h2 = e2 - f2;
    i2 = g2 / h2;

    cout << i2;

    return 0;
}