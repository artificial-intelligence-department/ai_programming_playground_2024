#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x = 0.25;
    double y = 1.31;
    double a = 3.5;
    double b = 0.9;
    const double PI = M_PI;

    double t1 = a * pow(x, 3) + b * pow(y, 2) - a * b;
    double t2 = tan(t1);
    double numerator = pow(sin(t1), 3);
    double denominator = cbrt(pow((a * pow(x, 3) + b * pow(y, 2) - a), 2) + PI);
    

    double P = fabs(numerator / denominator) + t2;

    cout << "The value of P is: " << P << endl;

    return 0;
}
