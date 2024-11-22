#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a = 0.5;
    double b = 2.9;
    double x = 0.3;

    double U_1 = pow(a, 3) + exp(-x) * cos(b * x);
    double U_2 = b * x - exp(-x) * sin(b * x) + 1;

    if (U_2 == 0) {
        cout << "Error: Division by zero in U calculation." << endl;
        return -1;
    }

    double U_final = U_1 / U_2;

    cout << "U =\t" << U_final << endl;

    double F_final = exp(2 * x) * log(a + x) - pow(b, 3 * x) * log(fabs(x - b));

    if (a + x <= 0 || fabs(x - b) <= 0) {
        cout << "Error: Logarithm of non-positive number." << endl;
        return -1;
    }

    cout << "F =\t" << F_final << endl;
    return 0;
}