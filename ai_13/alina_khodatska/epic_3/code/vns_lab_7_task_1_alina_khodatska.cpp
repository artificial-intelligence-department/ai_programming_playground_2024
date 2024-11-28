#include <iostream>
#include <cstdarg>  
#include <sstream> // включення бібліотеки для роботи зі стрічками

std::string toOctal(int number) {  // функція для переведення числа в вісімкову систему числення
    std::ostringstream result;
    do {
        int remainder = number % 8;
        result << remainder;
        number /= 8;
    } while (number > 0);

    std::string octal = result.str();
    std::reverse(octal.begin(), octal.end());
    return octal;
}
void convertToOctal(int count, ...) {   // Функції зі змінною кількістю параметрів (еліпсис)
    va_list args;  // тип для зберігання аргументів
    va_start(args, count);  // макрос для отримання поточного аргументу
    for (int i = 0; i < count; ++i) {
        int number = va_arg(args, int);
        std::string octal = toOctal(number);
        std::cout << "Decimal: " << number << " -> Octal: " << octal << std::endl;
    }
    va_end(args);  // макрос для очищення пам'яті
}
int main() {
    std::cout << "Conversion with 3 parameters:" << std::endl;
    convertToOctal(3, 10, 20, 30);  // виклик функції зі змінною кількістю параметрів

    std::cout << "\nConversion with 5 parameters:" << std::endl;
    convertToOctal(5, 15, 25, 35, 45, 55);

    std::cout << "\nConversion with 8 parameters:" << std::endl;
    convertToOctal(8, 8, 16, 24, 32, 40, 48, 56, 64);

    return 0;
}
