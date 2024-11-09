#include <iostream>
#include <cstdarg>

int EightToTen(int eight) {
    int ten = 0;
    int base = 1;

    while (eight > 0) {
        int lastDigit = eight % 10;
        eight /= 10;
        ten += lastDigit * base;
        base *= 8;
    }

    return ten;
}

int octalToDecimalSum(int count, ...) {
    va_list args;
    va_start(args, count);
    int decimalSum = 0;

    for (int i = 0; i < count; ++i) {
        int eight = va_arg(args, int);
        decimalSum += EightToTen(eight);
    }

    va_end(args);
    return decimalSum;
}

int main() {
    std::cout << "3 параметри: " << octalToDecimalSum(3, 10, 20, 30) << std::endl;
    std::cout << "6 параметрів: " << octalToDecimalSum(6, 10, 20, 30, 40, 50, 60) << std::endl;
    std::cout << "7 параметрів: " << octalToDecimalSum(7, 1, 2, 3, 4, 5, 6, 7) << std::endl;

    return 0;
}
