#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення точного значення y
double exactFunction(double x) {
    return (1.0 / 4) * log((1 + x) / (1 - x)) + (1.0 / 2) * atan(x);
}

// Функція для обчислення значення y за розкладом в степеневий ряд для заданого n
double seriesApproximation(double x, int n) {
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += pow(x, 4 * i + 1) / (4 * i + 1);
    }
    return sum;
}

// Функція для обчислення значення y за розкладом в степеневий ряд для заданої точності epsilon
double seriesApproximationEpsilon(double x, double epsilon) {
    double sum = 0;
    int i = 0;
    double term;
    do {
        term = pow(x, 4 * i + 1) / (4 * i + 1);
        sum += term;
        ++i;
    } while (fabs(term) >= epsilon);
    return sum;
}

int main() {
    double a = 0.1, b = 0.8;
    int k = 10;
    int n = 3;
    double epsilon = 0.0001;
    double step = (b - a) / k;

    cout << fixed << setprecision(8);
    cout << "x\tExact\tSeries (n=3)\tSeries (epsilon=0.0001)\n";

    for (double x = a; x <= b; x += step) {
        double exactValue = exactFunction(x);
        double seriesValueN = seriesApproximation(x, n);
        double seriesValueEpsilon = seriesApproximationEpsilon(x, epsilon);

        cout << x << "\t" << exactValue << "\t" << seriesValueN << "\t\t" << seriesValueEpsilon << "\n";
    }

    return 0;
}
