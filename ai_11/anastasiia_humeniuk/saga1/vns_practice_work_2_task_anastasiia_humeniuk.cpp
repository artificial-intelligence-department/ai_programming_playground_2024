#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a = 2;
    double b = 3;
    double c = 7;
    double hx = 0.31;

    double x_start = 0;
    double x_end = 5;

    for (double x = x_start; x <= x_end; x += hx) {
        double y;

        if (x < 2) {
            y = pow(a, b - x) + c;
        } else if (x >= 2 && x <= 4) {
            y = pow(b, c - x) + a;
        } else { 
            y = pow(c, a - x) + b;
        }

        cout << "x = " << x << ", y = " << y << endl;
    }

    return 0;
}
