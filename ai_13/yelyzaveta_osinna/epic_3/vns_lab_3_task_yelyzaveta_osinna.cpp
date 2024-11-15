#include <iostream>
#include <cmath> // Потрібно для функцій exp та fabs
#include <iomanip>

using namespace std;

// Функція для обчислення e^x за розкладом у ряд з фіксованим n
double power_series_fixed_n(double x, int n) {
    double sum = 1.0; // Початкове значення (перший член ряду для n=0)
    double term = 1.0; // Початковий член ряду
    for (int i = 1; i <= n; i++) {
        term *= x / i; // Наступний член ряду: x^i / i!
        sum += term; // Додаємо член до суми
    }
    return sum;
}

// Функція для обчислення e^x за розкладом у ряд з точністю epsilon
double power_series_with_epsilon(double x, double epsilon) {
    double sum = 1.0; // Початкове значення (перший член ряду для n=0)
    double term = 1.0; // Початковий член ряду
    int i = 1; // Починаємо з першого доданку
    while (fabs(term) > epsilon) {
        term *= x / i; // Наступний член ряду: x^i / i!
        sum += term; // Додаємо член до суми
        i++;
    }
    return sum;
}

int main() {
    double a = 1.0, b = 2.0; // Межі для x
    int k = 10; // Кількість інтервалів
    double step = (b - a) / k; // Крок для x
    int n = 10; // Фіксована кількість членів для частини (а)
    double epsilon = 0.0001; 

    cout << "|x| |Сума для n = "  << n << "|" << setw(20) << " |Сума для ε = " << epsilon << "|" << setw(20) << " |Точне значення e^x|\n";
    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i <= k; i++) {
        double x = a + i * step; 

        double sum_fixed_n = power_series_fixed_n(x, n);

        double sum_with_epsilon = power_series_with_epsilon(x, epsilon);

        double exact_value = exp(x);

        cout << x << "\t" << sum_fixed_n << "\t\t " << sum_with_epsilon << "\t\t" << exact_value << endl;
    }

    return 0;
}
