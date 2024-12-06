#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 2.4;
    double hx = 0.5;
    double x_start = -3.0;
    double x_end = 3.0;

    for (double x = x_start; x <= x_end; x += hx) {
        if (x == -1) {
            cout << "x = " << x << ": Division by zero. Skipping calculation." << endl;
            continue;
        }
        double numerator = pow(a, x) * log(abs(x + 8));
        double denominator = x + 1;
        double z = numerator / denominator;

        cout << "For x = " << x << ", z = " << z << endl;
    }

    return 0;
}
