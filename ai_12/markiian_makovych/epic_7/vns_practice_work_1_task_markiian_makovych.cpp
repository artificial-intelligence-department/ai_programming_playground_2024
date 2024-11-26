#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double R, Y;
    double a = 0.3, b = 0.9, x = 0.53;

    Y = (pow(a, 2 * x) + pow(b, -x) * cos(a + b) * x) / (abs(x + 1));

    R = sqrt(pow(x, 2) + b) - (pow(b, 2) * pow(sin(x + a), 3) / x);

    cout << "Y = " << Y << endl;
    cout << "R = " << R << endl;

    return 0;
}