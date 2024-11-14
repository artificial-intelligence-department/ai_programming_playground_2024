#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Функція для обчислення суми ряду для заданого n
double sumSeriesFixedN(double x, int n) {
    double sum = 0.0;
    for (int k = 1; k <= n; ++k) {
        sum += pow(-1, k) * pow(1 + x, 2 * k) / k;
    }
    return sum;
}

// Функція для обчислення суми ряду з точністю eps
double sumSeriesWithPrecision(double x, double eps) {
    double sum = 0.0;
    double term;
    int k = 1;
    do {
        term = pow(-1, k) * pow(1 + x, 2 * k) / k;
        sum += term;
        ++k;
    } while (fabs(term) >= eps);
    return sum;
}

int main() {
    double a = -2.0, b = -0.1;  // Початок і кінець діапазону значень x
    int k = 10;                 // Кількість кроків
    double step = (b - a) / k;   // Крок зміни x
    int n = 40;                  // Задане значення n
    double eps = 0.0001;         // Задана точність eps

    cout << "Обчислення функції" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;

        // Обчислення суми для заданого n = 40
        double sumN = sumSeriesFixedN(x, n);

        // Обчислення суми з точністю eps
        double sumEps = sumSeriesWithPrecision(x, eps);

        // Точне значення функції
        double exactValue = log(1.0 / (2 + 2 * x + x * x));

        // Вивід у заданому форматі
        cout << fixed << setprecision(5);
        cout << "X=" << x << "\tSN=" << sumN << "\tSE=" << sumEps << "\tY=" << exactValue << endl;
    }

    return 0;
}
