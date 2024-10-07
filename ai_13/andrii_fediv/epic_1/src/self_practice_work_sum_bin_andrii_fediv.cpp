#include <iostream>
#include <string>
#include <bitset>

std::string decimalToBinary(int decimal) {
    // Використовуємо std::bitset для конвертації десяткового числа в двійкове
    return std::bitset<32>(decimal).to_string();
}

int binaryToDecimal(const std::string& binary) {
    return std::stoi(binary, nullptr, 2);
}

std::string addBinary(const std::string& a, const std::string& b) {
    int decimalA = binaryToDecimal(a);
    int decimalB = binaryToDecimal(b);
    int sum = decimalA + decimalB;
    return decimalToBinary(sum);
}

int main() {
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Перетворюємо числа в двійкову систему
    std::string binaryNum1 = decimalToBinary(num1);
    std::string binaryNum2 = decimalToBinary(num2);

    // Додаємо двійкові числа
    std::string binarySum = addBinary(binaryNum1, binaryNum2);

    // Виводимо результати
    std::cout << "First number in binary: " << binaryNum1 << std::endl;
    std::cout << "Second number in binary: " << binaryNum2 << std::endl;
    std::cout << "Sum in binary: " << binarySum << std::endl;

    return 0;
}
