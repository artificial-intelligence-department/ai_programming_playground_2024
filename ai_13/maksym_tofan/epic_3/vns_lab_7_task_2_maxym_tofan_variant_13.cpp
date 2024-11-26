#include <iostream>

void toDecimal(int numerator, int denominator) {
    double decimal = static_cast<double>(numerator) / denominator;
    std::cout << "Десятковий дріб: " << decimal << std::endl;
}

int main() {
    int numerator, denominator;
    std::cout << "Введіть чисельник і знаменник звичайного дробу: ";
    std::cin >> numerator >> denominator;

    toDecimal(numerator, denominator);

    return 0;
}
    