#include <iostream>
#include <cmath>

int main() {
    double m = 0.7, x = 1.77, a = 0.5, b = 1.08;

    double Z = (sin(x) / sqrt(1 + pow(m, 3) * pow(sin(x), 2))) - (m * x * log(m * x));

    double S = exp(-a * x) * sqrt(x + 1) + exp(b * x) * sqrt(abs(x - 3));

    std::cout << "Z = " << Z << "\nS = " << S << std::endl;
    return 0;
}
