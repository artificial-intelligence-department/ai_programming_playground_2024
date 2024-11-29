#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x_start = 0.5;
    double x_end = 3.1;
    double x_krok = 0.21;
    double a_start = -0.1;
    double a_end = -1.4;
    double a_krok = 0.1;
    double b = 1.5;

    std::cout << std::fixed << std::setprecision(4); // Встановлення формату виведення

    for (double a = a_start; a >= a_end; a -= a_krok) {
        for (double x = x_start; x <= x_end; x += x_krok) {
            double y;
            if (x < b) {
                y = sin(fabs(a * x + pow(b, a)));
            } else {
                y = cos(fabs(a * x - pow(b, a)));
            }
            std::cout << "a = " << a << ", x = " << x << ", y = " << y << std::endl;
        }
    }

    return 0;
}
