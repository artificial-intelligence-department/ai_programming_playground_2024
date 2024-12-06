#include <iostream>
#include <cmath>

int main() {
    double m = 2, c = 1, x = 1.2, b = 0.7;

    double phi = sqrt(m * tan(x) + c * sin(x));
    double xi = m * cos(b * x + sin(x)) + pow(c, 3);

    std::cout << "phi = " << phi << "\nxi = " << xi << std::endl;

    return 0;
}
