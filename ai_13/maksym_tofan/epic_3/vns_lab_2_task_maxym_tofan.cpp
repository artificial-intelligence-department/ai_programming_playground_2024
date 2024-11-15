#include <iostream>
#include <cmath>

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    const double epsilon = 0.0001;
    double sum = 0.0;
    double term;
    int n = 0;

    do {
        double numerator = pow(3, n) * factorial(n);
        double denominator = factorial(3 * n);
        term = numerator / denominator;
        sum += term;
        ++n;
    } while (fabs(term) >= epsilon);

    std::cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << std::endl;

    return 0;
}
