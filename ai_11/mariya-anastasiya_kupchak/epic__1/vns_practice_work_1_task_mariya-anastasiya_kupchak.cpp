// Variant 14

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a = 1.1;
    double b = 0.004;
    double x = 0.2;

    double y, z;
    double opy1, opy2, opy3, opy4;
    double opz1, opz2, opz3, opz4;

    opy1 = pow(a, 2);
    opy2 = sin(opy1);
    opy3 = pow(opy2, 3);
    opy4 = pow((x / b), (1 / 3));

    y = opy3 - opy4;

    opz1 = pow(x, 2) / a;
    opz2 = pow((x + b), 3);
    opz3 = cos(opz2);
    opz4 = pow(opz3, 2);

    z = opz1 + opz4;

    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}
