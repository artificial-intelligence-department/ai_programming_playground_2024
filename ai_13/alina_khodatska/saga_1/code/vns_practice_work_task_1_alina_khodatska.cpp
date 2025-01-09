#include <iostream>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

int main() {
    double x = 0.25;
    double y = 1.31;
    double a = 3.5;
    double b = 0.9;

    double expression = a * pow(x, 3) + b * pow(y, 2) - a * b;
    double numerator = pow(sin(expression), 3);
    double denominator = cbrt(pow(expression, 2) + M_PI);  // cbrt - cube root
    double tangent = tan(expression);

    double P = numerator / denominator + tangent;

    cout << "Result P = " << P << endl;

    return 0;
}
