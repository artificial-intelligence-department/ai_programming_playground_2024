#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    // Введення двох чисел
    std::cout << "Введіть перше число: ";
    std::cin >> num1;
    std::cout << "Введіть друге число: ";
    std::cin >> num2;

    // Вибір операції
    std::cout << "Виберіть операцію (+, -, *, /): ";
    std::cin >> operation;

    // Виконання операції в залежності від вибору користувача
    if (operation == '+') {
        result = num1 + num2;
        std::cout << "Результат додавання: " << result << std::endl;
    } else if (operation == '-') {
        result = num1 - num2;
        std::cout << "Результат віднімання: " << result << std::endl;
    } else if (operation == '*') {
        result = num1 * num2;
        std::cout << "Результат множення: " << result << std::endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            std::cout << "Результат ділення: " << result << std::endl;
        } else {
            std::cout << "Ділення на нуль неможливе!" << std::endl;
        }
    } else {
        std::cout << "Невідома операція!" << std::endl;
    }

    return 0;
}
