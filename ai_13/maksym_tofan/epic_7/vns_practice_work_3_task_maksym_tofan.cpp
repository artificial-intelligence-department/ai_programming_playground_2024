#include <iostream>
#include <cmath>

int main() {
    const double hx = 0.5;
    const double x_start = -2.5;
    const double x_end = 2.0;

    std::cout << "x\t\tz\t\ty" << std::endl;
    std::cout << "---------------------------" << std::endl;

    for (double x = x_start; x <= x_end; x += hx) {
        double z = fabs(x) + pow(x, 2);
        double y = z * (pow(sin(2 + x), 2) / (2 + x));
        std::cout << x << "\t" << z << "\t" << y << std::endl;
    }

    return 0;
}
