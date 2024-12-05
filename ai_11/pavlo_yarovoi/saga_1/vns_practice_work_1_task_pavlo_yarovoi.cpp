#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a = 1.5, b = 15.5, x = -2.9;

    cout << "Given values:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "x = " << x << endl;

    double y = pow(cos(pow(x, 3)), 2) - (x / sqrt(pow(a, 2) + pow(b, 2)));
    double P = sqrt(pow(x, 2) + b) - pow(b, 2) * pow(sin(x + a), 3) / (x * y);

    cout << "Results:" << endl;
    cout << "y = " << fixed << setprecision(3) << y << endl;
    cout << "P = " << fixed << setprecision(3) << P << endl;

    return 0;
}
