#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "enter 1 number: ";
    std::cin >> num1;

    std::cout << "enter operation (+, -, *, /): ";
    std::cin >> operation;

    std::cout << "enter 1 number: ";
    std::cin >> num2;

    switch (operation) {
        case '+':
            std::cout << "result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error" << std::endl;
            }
            break;
        default:
            std::cout << "Error" << std::endl;
            break;
    }

    return 0;
}