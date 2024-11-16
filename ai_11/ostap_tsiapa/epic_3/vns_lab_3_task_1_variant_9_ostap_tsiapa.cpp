#include <iostream>
#include <cmath>

using namespace std;

// Функція для обчислення факторіалу
double factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

// Точне значення функції
double exactFunctionValue(double x) {
    return (1.0 / 4.0) * log((1.0 + x) / (1.0 - x)) + (1.0 / 2.0) * atan(x);
}

int main() {
    double a = 0.1;      // Початкове значення x
    double b = 0.8;      // Кінцеве значення x
    int k = 10;          // Кількість кроків
    int n = 3;          // Задане значення n
    double epsilon = 0.0001; // Задана точність

    double step = (b - a) / k;

    cout << "Обчислення функції" << endl;

    for (double x = a; x <= b; x += step) {
        double SN = 0.0;
        double SE = 0.0;
        double exactValue = exactFunctionValue(x);

        // Обчислення SN (заданого n)
        for (int i = 0; i < n; ++i) {
            SN += pow(x, 4*i + 1) / (4*i + 1);
        }

        // Обчислення SE (заданої точності епсилон)
        int i = 0;
        double element;
        do {
            element = pow(x, 4*i + 1) / (4*i + 1);
            SE += element;
            ++i;
        } while (element >= epsilon);

        // Вивід результатів
        cout << "X=" << x << " SN=" << SN << " SE=" << SE << " Y=" << exactValue << endl;
    }

    return 0;
}
