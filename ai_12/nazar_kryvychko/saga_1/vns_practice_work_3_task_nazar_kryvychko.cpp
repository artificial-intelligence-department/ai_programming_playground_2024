#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <iomanip>

// Функція для обчислення об'єму циліндра (перевантаження функції)
double calculateVolume(double radius, double height) {
    return M_PI * std::pow(radius, 2) * height;
}

// Функція для обчислення послідовного опору трьох резисторів (перевантаження функції)
double calculateResistance(double R1, double R2, double R3) {
    return R1 + R2 + R3;
}

// Рекурсивна функція для обчислення факторіалу числа (для демонстрації рекурсії)
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    std::cout << "Обчислення об'єму циліндра.\n";
    std::cout << "Введіть початкові дані:\n";

    double radius, height;
    while (true) {
        std::cout << "радіус підстави (см) > ";
        std::cin >> radius;
        if (radius < 0) {
            std::cout << "Радіус не може бути від'ємним! Пропускаємо цю ітерацію.\n";
            continue;
        }

        std::cout << "висоту циліндра (см) > ";
        std::cin >> height;
        if (height < 0) {
            std::cout << "Висота не може бути від'ємною! Пропускаємо цю ітерацію.\n";
            continue;
        }

        double volume = calculateVolume(radius, height);
        std::cout << "Об'єм циліндра: " << std::fixed << std::setprecision(2) << volume << " см куб.\n";
        break;  // Використання оператора break для виходу з циклу після успішного введення
    }

    std::cout << "Для завершення натисніть клавішу <Enter>.\n";
    std::cin.ignore();
    std::cin.get();

    std::cout << "\nОбчислення опору електричний ланцюгу, що складається з трьох\n";
    std::cout << "послідовно сполучених резисторів.\n";

    double R1, R2, R3;
    std::cout << "Введіть опір першого резистора (Ом) > ";
    std::cin >> R1;
    std::cout << "Введіть опір другого резистора (Ом) > ";
    std::cin >> R2;
    std::cout << "Введіть опір третього резистора (Ом) > ";
    std::cin >> R3;

    double totalResistance = calculateResistance(R1, R2, R3);
    std::cout << "Загальний опір ланцюгу: " << totalResistance << " Ом.\n";

    int num;
    std::cout << "\nВведіть число для обчислення факторіалу: ";
    std::cin >> num;
    if (num < 0) {
        std::cout << "Факторіал не визначено для від'ємних чисел.\n";
    } else {
        int result = factorial(num);
        std::cout << "Факторіал числа " << num << " = " << result << ".\n";
    }

    return 0;
}
