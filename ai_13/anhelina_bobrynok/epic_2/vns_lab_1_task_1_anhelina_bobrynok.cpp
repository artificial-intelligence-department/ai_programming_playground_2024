#include <iostream>
#include <cmath>

int main() {
    // Задаємо значення a і b
    float a_f = 1000.0f, b_f = 0.0001f;
    double a_d = 1000.0, b_d = 0.0001;

    // Обчислення
    float result_f = (pow(a_f - b_f, 3) - pow(a_f, 3) + 3 * pow(a_f, 2) * b_f)/(b_f - a_f * pow(b_f, 3));
    double result_d = (pow(a_d - b_d, 3) - pow(a_d, 3) + 3 * pow(a_d, 2) * b_d) / (b_d - a_d * pow(b_d, 3));

    // Виведення результатів
    std::cout << "Result with float: " << result_f << std::endl;
    std::cout << "Result with double: " << result_d << std::endl;

    return 0;
}
