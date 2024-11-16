// var 13
#include <iostream>
#include <cmath>

int main() {
    double a = 1.7, b = 2.3;
    double hx = 0.9, hy = 1.0;

    for (double x = -1; x <= 1; x += hx) {
        for (double y = -2; y <= 2; y += hy) {
            double z;
            if (x * y > 0) { // if used
                z = log(sqrt(a * pow(x, 2) + b * pow(y, 3)));
            } else {
                z = pow(a, x) + pow(b, y);
            }
            std::cout << "z = " << z << std::endl;
        }
    }
}
