#include <iostream>
#include <cmath> 

using namespace std;

double logarithm(double x) {
    if (x <= 0) {
        cout << "Помилка: натуральний логарифм визначений тільки для x > 0." << endl;
        return 0;
    }
    return log(x);
}

double logarithm(double x, double base) {
    if (x <= 0 || base <= 1) {
        cout << "Помилка: натуральний логарифм визначений тільки для x > 0 і base > 1." << endl;
        return 0;
    }
    return log(x) / log(base);
}

double logarithm10(double x) {
    if (x <= 0) {
        cout << "Помилка: десятковий логарифм визначений тільки для x > 0." << endl;
        return 0;
    }
    return log10(x);
}

int main() {
    double value1 = 10.0;
    double value2 = 100.0;

    cout << "Натуральний логарифм " << value1 << " = " << logarithm(value1) << endl;
    cout << "Десятковий логарифм " << value2 << " = " << logarithm10(value2) << endl;
    cout << "Логарифм " << value1 << " з основою 2 = " << logarithm(value1, 2) << endl;

    return 0;
}
