#include <iostream>
#include <cmath>

long double factorial(int n) {
    long double fact = 1.0;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int main() {
    const int terms = 10;
    long double sum = 0.0;

    for (int n = 1; n <= terms; ++n) {
        long double term = factorial(n) / pow(n, sqrt(n));
        sum += term;
        std::cout << "Term " << n << ": " << term << std::endl;
    }

    std::cout << "Sum of the first " << terms << " terms: " << sum << std::endl;

    return 0;
}
