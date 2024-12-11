#include<bits/stdc++.h>

using namespace std;

int main()
{
    double x = 1.45;
    double y = -1.22;
    double z = 3.5;
    double pi = 3.1415926;
    double b, a, temp1, temp2;

    b = 1 + (z*z)/(3 + z*z / 5);
    temp1 = cos(x - pi / 6);
    temp2 = sin(y);
    a = (2 * temp1 * b) / (0.5 + temp2 * temp2);

    cout << a;

    return 0;
}