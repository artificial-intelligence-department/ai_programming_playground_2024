#include <iostream>
#include <cmath>

double exact_value(double x) {
    return 0.5 * log(x);
}

double series_value(double x, int n) {
    double sum = 0.0;
    double term = 1.0;
    double ratio = (x - 1) / (x + 1);

    for (int k = 0; k < n; ++k) {
        term = (1.0 / (2 * k + 1)) * pow(ratio, 2 * k + 1);
        sum += term;
    }
    return sum;
}

double series_value_with_epsilon(double x, double epsilon) {
    double sum = 0.0;
    double term = 1.0;
    double ratio = (x - 1) / (x + 1);
    int k = 0;

    while (fabs(term) >= epsilon) {
        term = (1.0 / (2 * k + 1)) * pow(ratio, 2 * k + 1);
        sum += term;
        ++k;
    }
    return sum;
}

int main() {
    double a = 0.2, b = 1.0;
    int k = 10;
    double epsilon = 0.0001;
    int n = 10;
    double step = (b - a) / k;

    std::cout << "x\tExact\tSeries (n=10)\tSeries (epsilon=0.0001)\n";
    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;
        double exact = exact_value(x);
        double approx_n = series_value(x, n);
        double approx_epsilon = series_value_with_epsilon(x, epsilon);

        std::cout << x << "\t" << exact << "\t" << approx_n << "\t" << approx_epsilon << "\n";
    }

    return 0;
}
