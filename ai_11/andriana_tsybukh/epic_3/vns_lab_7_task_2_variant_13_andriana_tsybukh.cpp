#include <iostream>
#include <cmath>

using namespace std;

// Функція для знаходження НСД (найбільшого спільного дільника)
int nsd(int a, int b) {
    return b == 0 ? a : nsd(b, a % b);
}

// Перетворення десяткового дробу у звичайний
void convert(double decimal) {
    int denominator = 1;

    // Перетворення у ціле число
    while (decimal != floor(decimal)) {
        decimal *= 10;
        denominator *= 10;
    }

    int numerator = static_cast<int>(decimal);

    // Спрощення дробу
    int divisor = nsd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    cout << "Десятковий дріб -> Звичайний дріб: " << numerator << "/" << denominator << "\n";
}

// Перетворення звичайного дробу у десятковий
void convert(int numerator, int denominator) {
    if (denominator == 0) {
        cout << "Помилка: знаменник не може бути нулем.\n";
        return;
    }

    double decimal = static_cast<double>(numerator) / denominator;
    cout << "Звичайний дріб -> Десятковий дріб: " << decimal << "\n";
}

int main() {
    // Тестування функцій
    cout << "Перетворення десяткового дробу у звичайний:\n";
    convert(0.25);   // Очікуваний результат: 1/4
    convert(0.75);   // Очікуваний результат: 3/4

    cout << "\nПеретворення звичайного дробу у десятковий:\n";
    convert(1, 4);   // Очікуваний результат: 0.25
    convert(3, 4);   // Очікуваний результат: 0.75

    return 0;
}
