#include <iostream>
#include <cmath>
using namespace std;

// Точне значення функції
double exact_value(double x) {
    return (exp(x) - exp(-x)) / 2;
}

// Рекурсивна функція для обчислення факторіала
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Функція для обчислення SN для заданого числа членів ряду n
double sum_series_n(double x, int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        double term = pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sum += term;
    }
    return sum;
}

// Функція для обчислення SN для заданої точності epsilon
double sum_series_epsilon(double x, double epsilon) {
    double sum = 0.0;
    double term;
    int n = 0;
    do {
        term = pow(x, 2 * n + 1) / factorial(2 * n + 1);
        sum += term;
        n++;
    } while (fabs(term) > epsilon);
    return sum;
}

int main() {
    double a = 0.1, b = 1.0;
    int k = 10;
    double epsilon = 0.0001;
    int n = 20; // Кількість членів ряду для часткового обчислення

    // Зміна параметра x
    for (double x = a; x <= b; x += (b - a) / k) {
        // Обчислення SN для заданого n
        double sn_n = sum_series_n(x, n);
        // Обчислення SN для заданої точності epsilon
        double sn_epsilon = sum_series_epsilon(x, epsilon);
        // Точне значення
        double exact = exact_value(x);

        // Виведення результатів
        cout << "X = " << x << " SN = " << sn_n << " SE = " << sn_epsilon << " Y = " << exact << endl;
    }

    return 0;
}
