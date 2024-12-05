#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Обчислення точного значення функції
double exactFunction(double x) {
    return (x * x / 4 + x / 2 + 1) * exp(x / 2);
}

// Розрахунок суми ряду для заданої кількості членів
double seriesSumN(double x, int n) {
    double sum = 0;
    for (int i = 0; i <= n; ++i) {
        double term = (i * i + 1) * pow(x / 2, i) / tgamma(i + 1); // tgamma(i+1) = i!
        sum += term;
    }
    return sum;
}

// Розрахунок суми ряду для заданої точності
double seriesSumE(double x, double epsilon) {
    double sum = 0;
    double term;
    int i = 0;
    do {
        term = (i * i + 1) * pow(x / 2, i) / tgamma(i + 1);
        sum += term;
        ++i;
    } while (fabs(term) > epsilon);
    return sum;
}

int main() {
    // Межі для x
    double a = 0.0, b = 1.0;
    int k = 10; // Кількість кроків
    double step = (b - a) / k;
    int n = 30; // Задане число членів
    double epsilon = 0.0001; // Задана точність

    cout << fixed << setprecision(6);
    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;
        double sn = seriesSumN(x, n);         // Сума для заданого n
        double se = seriesSumE(x, epsilon);  // Сума для заданої точності
        double y = exactFunction(x);         // Точне значення функції

        // Вивід результатів у потрібному форматі
        cout << "X=" << x << " " << "SN=" << sn << " " << "SE=" << se << " " << "sY=" << y << endl;
    }

    return 0;
}