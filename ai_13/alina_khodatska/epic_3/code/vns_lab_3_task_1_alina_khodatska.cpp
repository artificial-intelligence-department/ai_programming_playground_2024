#include <iostream>
#include <cmath>
#include <vector>

const double PI = 3.14159265358979323846; // Визначення числа ?

// Функція для обчислення точного значення функції y
double exactFunction(double x) {
    return -0.5 * std::log(1 - 2 * x * std::cos(PI / 3) + x * x);
}

// Функція для обчислення значення функції через степеневий ряд для заданого n
double seriesFunctionN(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += (std::pow(x, i) * std::cos(i * PI / 3)) / i;
    }
    return sum;
}

// Функція для обчислення значення функції через степеневий ряд з точністю epsilon
double seriesFunctionEpsilon(double x, double epsilon) {
    double sum = 0.0;
    double term;
    int i = 1;
    do {
        term = (std::pow(x, i) * std::cos(i * PI / 3)) / i;
        sum += term;
        ++i;
    } while (std::abs(term) >= epsilon);
    return sum;
}

int main() {
    double a = 0.1; // Початок діапазону
    double b = 0.8; // Кінець діапазону
    int k = 10; // Кількість кроків
    int n = 35; // Задане значення n
    double epsilon = 0.0001; // Точність

    double step = (b - a) / k;
    std::vector<double> x_values;

    // Заповнення вектора значеннями x
    for (int i = 0; i <= k; ++i) {
        x_values.push_back(a + i * step);
    }

    std::cout << "x\tExact\tSeries N\tSeries Epsilon\n";
    std::cout << "-----------------------------------------\n";

    // Обчислення значень функції для кожного x
    for (double x : x_values) {
        double exact = exactFunction(x);
        double series_n = seriesFunctionN(x, n);
        double series_epsilon = seriesFunctionEpsilon(x, epsilon);

        std::cout << x << "\t" << exact << "\t" << series_n << "\t" << series_epsilon << "\n";
    }

    return 0;
}
