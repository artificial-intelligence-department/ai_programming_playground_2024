#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x_start = 0.5, x_end = 3.1, hx = 0.2;
    double a_start = 0.1, ha = 0.3;
    double x = x_start, a = a_start;

    while (x <= x_end && a <= 2.0) {
        double y;

        if (x > 2) {
            y = cos(a * x + 2); 
        } else {
            y = tan(fabs(x - 2 * a)); 
        }

        cout << "x = " << x << ", a = " << a << ", y = " << y << endl;

        x += hx;
        a += ha;
    }

    return 0;
}