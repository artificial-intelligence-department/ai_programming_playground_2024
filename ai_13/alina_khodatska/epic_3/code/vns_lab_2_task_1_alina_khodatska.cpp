#include <iostream>
#include <cmath>

// Рекурсивна функція для обчислення факторіала числа
unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);  // Рекурсивний виклик
}

// Функція для обчислення n-го члена ряду
double computeTerm(int n) {
    return (pow(2, n) * factorial(n)) / pow(n, n);  // повернення значення n-го члена ряду
}

int main() {
    const double epsilon = 0.0001; // Точність
    double sum = 0.0; // Сума ряду
    double term; // Поточний член ряду
    int n = 1; // Індекс члена ряду

    // Цикл do while для обчислення суми ряду
    do {
        term = computeTerm(n);
        sum += term;
        ++n;
    } while (std::abs(term) >= epsilon);

    std::cout << "Row sum with accuracy epsilon = " << epsilon << " equals: " << sum << std::endl;

    return 0;  // Повернення 0
}
