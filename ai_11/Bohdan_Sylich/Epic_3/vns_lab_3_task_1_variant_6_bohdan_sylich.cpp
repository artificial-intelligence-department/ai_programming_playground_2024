#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення точного значення функції
double exactFunction(double x) {
    return exp(cos(x * sin(M_PI / 4.0)));
}

// Функція для обчислення значення за рядом Тейлора
double taylorSeriesFixedN(double x, int n) {
    double result = 1.0; 
    double term = 1.0; 
    for (int i = 1; i <= n; ++i) {
        term *= (cos(M_PI / 4.0) * x) / i;
        result += term;
    }

    return result;
}

// Функція для обчислення значення за рядом Тейлора із заданою точністю ε
double taylorSeriesWithEpsilon(double x, double epsilon) {
    double result = 1.0;
    double term = 1.0;
    int i = 1;

    while (abs(term) > epsilon) {
        term *= (cos(M_PI / 4.0) * x) / i;
        result += term;
        ++i;
    }

    return result;
}

int main() {
    double a = 0.1, b = 1.0;
    int k = 10;
    int n = 25;
    double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << fixed << setprecision(8);
    cout << "x\tExact\t\tTaylor(n=25)\tTaylor(epsilon=0.0001)\n";

    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;
        double exact = exactFunction(x);
        double taylorN = taylorSeriesFixedN(x, n);
        double taylorEps = taylorSeriesWithEpsilon(x, epsilon);

        cout << fixed << setprecision(4) << x << "\t" << exact << "\t" << taylorN << "\t" << taylorEps << "\n";
    }

    return 0;
}