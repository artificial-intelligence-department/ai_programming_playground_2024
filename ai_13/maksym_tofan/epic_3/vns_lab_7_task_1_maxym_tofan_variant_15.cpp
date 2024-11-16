#include <iostream>
#include <cmath>
#include <numeric> // для std::gcd

// Структура для представлення звичайного дробу
struct Fraction {
    int numerator;
    int denominator;

    // Скорочення дробу
    void reduce() {
        int gcd_value = std::gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
    }
};

// Функція для перетворення десяткового дробу у звичайний
Fraction toFraction(double decimal) {
    const int precision = 100000; // точність до 5 знаків після коми
    int denominator = precision;
    int numerator = static_cast<int>(round(decimal * precision));

    Fraction fraction = {numerator, denominator};
    fraction.reduce();
    return fraction;
}

int main() {
    // Введення десяткового дробу
    double decimal;
    std::cout << "Введіть десятковий дріб: ";
    std::cin >> decimal;

    // Перетворення у звичайний дріб
    Fraction fraction = toFraction(decimal);
    std::cout << "Звичайний дріб: " << fraction.numerator << "/" << fraction.denominator << std::endl;

    return 0;
}
