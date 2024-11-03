#include <iostream>
#include <cmath>
using namespace std;

double exact_function(double x) {
    return pow(3, x);
}

// Функція для обчислення значення ряду для заданого n
double series_for_n(double x, int n) {
    double sum = 1;
    double term = 1;
    double ln3 = log(3);

    for (int i = 1; i <= n; i++) {
        term *= (x * ln3) / i;
        sum += term;
    }
    return sum;
}

// Функція для обчислення значення ряду з точністю ε
double series_for_epsilon(double x, double epsilon) {
    double sum = 1;
    double term = 1;
    double ln3 = log(3);
    int i = 1;

    while (fabs(term) > epsilon) {
        term *= (x * ln3) / i;
        sum += term;
        i++;
    }
    return sum;
}

int main() {
    double a = 0.1, b = 1.0, epsilon = 0.0001;
    int k = 10, n = 10;
    double step = (b - a) / k;

    cout << "x\tExact\tSeries (n=" << n << ")\tSeries (e=" << epsilon << ")" << endl;
    for (double x = a; x <= b; x += step) {
        cout << x << "\t" << exact_function(x) << "\t" 
             << series_for_n(x, n) << "\t\t" 
             << series_for_epsilon(x, epsilon) << endl;
    }
    return 0;
}
