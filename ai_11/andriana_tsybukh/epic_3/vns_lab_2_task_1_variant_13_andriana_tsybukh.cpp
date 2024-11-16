#include <iostream>
#include <cmath>
using namespace std;

// Факторіал
unsigned int factorial(int n) {
    unsigned int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    double epsilon = 0.0001;
    double sum = 0.0;
    int n = 0;

    while (true) {
        double a_n = pow(3, n) * factorial(n) / factorial(3 * n);
        sum += a_n;
        if (a_n < epsilon) {
            break;
        }
        n++;
    }

    cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << endl;

    return 0;
}
