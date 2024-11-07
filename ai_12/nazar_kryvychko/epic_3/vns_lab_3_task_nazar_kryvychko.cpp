#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Функція для обчислення точного значення f(x)
double exact_function(double x) {
    return -log(abs(2 * sin(x / 2))); 
}

// Функція для обчислення степеневого ряду до n-го члена
double series_sum(double x, int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += cos(i * x) / i;
    }
    return sum;
}

// Функція для обчислення ряду з заданою точністю
double series_sum_with_epsilon(double x, double epsilon) {
    double sum = 0.0;
    double term = 0.0;
    int i = 1;
    do {
        term = cos(i * x) / i;
        sum += term;
        ++i;
    } while (abs(term) > epsilon);
    return sum;
}

int main() {
    int k = 10;            // кількість кроків
    double epsilon = 0.0001; // точність для варіанту з епсілон
    int n_fixed = 40;       // значення n для варіанту з фіксованим n

    // Межі для x
    double a = M_PI / 5;
    double b = 9 * M_PI / 5;
    double step = (b - a) / k;

    // Обчислення для різних x
    cout << fixed << setprecision(6);
    for (int i = 0; i <= k; ++i) {
        double x = a + i * step;
        double exact = exact_function(x);               // Точне значення Y
        double series_n = series_sum(x, n_fixed);       // Значення SN (n = 40)
        double series_eps = series_sum_with_epsilon(x, epsilon); // Значення SE (точність)

        cout << "X= " << setw(8) << x
            << " SN=" << setw(10) << series_n
            << " SE=" << setw(10) << series_eps
            << " Y=" << setw(10) << exact << "\n";
    }

    return 0;
}
