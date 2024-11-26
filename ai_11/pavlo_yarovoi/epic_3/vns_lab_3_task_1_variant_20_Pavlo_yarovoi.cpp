#include <iostream>
#include <cmath>

using namespace std;

double Function(double x) {
    return (((x * x) / 4.0) + (x / 2.0) + 1) * exp(x / 2.0);
}

double factorial(int n) {
    double fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

double SeriesForN(double x, int n) {
    double sum = 1.0;
    double element = 1.0;
    for (int i = 1; i <= n; ++i) {
        element = ((x / 2.0) * element) / i;
        sum += ((i * i + 1) / factorial(i)) * element;
    }
    return sum;
}

double SeriesForEpsilon(double x, double epsilon) {
    double sum = 1.0;
    double element = 1.0;
    int i = 1;

    while (abs((i * i + 1) * element / factorial(i)) >= epsilon) {
        element = ((x / 2.0) * element) / i;
        sum += ((i * i + 1) / factorial(i)) * element;
        ++i;
    }
    return sum;
}

int main() {
    double a = 0.1, b = 1.0;
    int k = 10;
    int n = 30;
    const double epsilon = 0.0001;

    double step = (b - a) / k;

    cout << "Calculation results: " << endl;
    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;

        double just = Function(x);

        double seriesN = SeriesForN(x, n);

        double seriesEpsilon = SeriesForEpsilon(x, epsilon);

        cout << "X=" << x  << " SN=" << seriesN  << " SE=" << seriesEpsilon  << " Y=" << just << endl;
    }

    return 0;
}
