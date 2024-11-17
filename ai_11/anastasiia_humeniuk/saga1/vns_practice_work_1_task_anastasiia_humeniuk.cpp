#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x = 0.25, y = 0.79, z = 0.81;

    double numeratorP = 1 + pow(sin(x + 1), 2);
    double denominatorP = 2 + abs(x - 2 * pow(x, 3) / (1 + pow(x, 2) * pow(y, 3)));
    double P = numeratorP / denominatorP + pow(x, 4);

    double Q = pow(cos(atan(1 / z)), 2);

    cout << "P = " << P << endl;
    cout << "Q = " << Q << endl;

    return 0;
}
