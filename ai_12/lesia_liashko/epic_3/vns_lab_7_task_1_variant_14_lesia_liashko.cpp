#include <iostream>
#include <string>
#include <cstdarg>

// Функція для перетворення числа з двійкової в десяткову систему
int binaryToTen(int binary) {
    int ten = 0, base = 1;
    while (binary > 0) {
        int comma = binary % 10;
        binary /= 10;
        ten += comma * base;
        base *= 2;
    }
    return ten;
}

// Функція для перетворення числа з десяткової в трійкову систему
std::string TenToTernary(int ten) {
    std::string ternary;
    while (ten > 0) {
        ternary = std::to_string(ten % 3) + ternary;
        ten /= 3;
    }
    return ternary.empty() ? "0" : ternary;
}

// Функція зі змінною кількістю параметрів для перетворення чисел із двійкової в трійкову систему
void BinaryToTernary(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i) {
        int binary = va_arg(args, int);
        int decimal = binaryToTen(binary);
        std::string ternary = TenToTernary(decimal);
        std::cout << "Binary: " << binary << " -> Ternary: " << ternary << std::endl;
    }
    va_end(args);
}

// Функція main
int main() {
    std::cout << "Виклик з 3 параметрами:" << std::endl;
    BinaryToTernary(3, 101, 111, 1001);

    std::cout << "\nВиклик з 6 параметрами:" << std::endl;
    BinaryToTernary(6, 10, 11, 110, 1010, 1111, 10000);

    std::cout << "\nВиклик з 7 параметрами:" << std::endl;
    BinaryToTernary(7, 1, 10, 11, 100, 101, 110, 111);

    return 0;
}
