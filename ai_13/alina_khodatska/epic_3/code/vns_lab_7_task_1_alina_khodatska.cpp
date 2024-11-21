#include <iostream>
#include <cstdarg>
#include <sstream> // Для std::ostringstream

// Функція для перетворення одного числа з десяткової системи числення у вісімкову
std::string toOctal(int number) {
    std::ostringstream result;
    do {
        int remainder = number % 8;
        result << remainder;
        number /= 8;
    } while (number > 0);

    std::string octal = result.str();
    std::reverse(octal.begin(), octal.end()); // Перевертаємо рядок, оскільки ми будували його у зворотному порядку
    return octal;
}
// Функція зі змінною кількістю параметрів для перетворення чисел у вісімкову систему
void convertToOctal(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int number = va_arg(args, int);
        std::string octal = toOctal(number);
        std::cout << "Decimal: " << number << " -> Octal: " << octal << std::endl;
    }
    va_end(args);
}
int main() {
    std::cout << "Conversion with 3 parameters:" << std::endl;
    convertToOctal(3, 10, 20, 30);

    std::cout << "\nConversion with 5 parameters:" << std::endl;
    convertToOctal(5, 15, 25, 35, 45, 55);

    std::cout << "\nConversion with 8 parameters:" << std::endl;
    convertToOctal(8, 8, 16, 24, 32, 40, 48, 56, 64);

    return 0;
}
