#include <iostream>
#include <cmath>

// Функція для обчислення факторіала числа
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Функція для обчислення n-го члена ряду
double computeTerm(int n) {
    return (pow(2, n) * factorial(n)) / pow(n, n);
}

int main() {
    const double epsilon = 0.0001; // Точність
    double sum = 0.0; // Сума ряду
    double term; // Поточний член ряду
    int n = 1; // Індекс члена ряду

    // Цикл для обчислення суми ряду, поки член не стане меншим за epsilon
    do {
        term = computeTerm(n);
        sum += term;
        ++n;
    } while (std::abs(term) >= epsilon);

    // Виведення результату з відповідним заголовком
    std::cout << "Row sum with accuracy epsilon = " << epsilon << " equals: " << sum << std::endl;

    return 0;
}
