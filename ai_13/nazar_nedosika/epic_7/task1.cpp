#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x = 0.25;
    double y = 0.79;
    double z = 0.81;

    double numerator_P = 1 + pow(sin(x + 1), 2);
    double denominator_P = 2 + fabs(x - 2 * pow(x, 3) / (1 + pow(x, 2) * pow(y, 3)));
    double P = numerator_P / denominator_P + pow(x, 4);

    double Q = pow(cos(atan(1 / z)), 2);

    cout << "P = " << P << endl;
    cout << "Q = " << Q << endl;

    return 0;
}