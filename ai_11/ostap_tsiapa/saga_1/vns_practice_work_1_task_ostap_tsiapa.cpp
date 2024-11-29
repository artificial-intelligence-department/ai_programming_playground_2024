#include <iostream>
#include <cmath> // Необхідна для обчислень бібліотека

int main() {
    // Введення початкових даних
    double a = 3.2;
    double b = 17.5;
    double x = 4.8;

    // Обчислення значення Y
    double tan_x = tan(x);
    double tan_x_squared = tan_x * tan_x;
    double b_cubed = pow(b, 3);
    double sin_x_div_a = sin(x / a);
    double sin_x_div_a_squared = sin_x_div_a * sin_x_div_a;
    double Y = b_cubed * tan_x_squared - (a / sin_x_div_a_squared);

    // Обчислення значення Z
    double sqrt_3 = sqrt(3.0);
    double exp_neg_sqrt_3 = exp(-sqrt_3);
    double cos_bx_div_a = cos((b * x) / a);
    double Z = a * exp_neg_sqrt_3 * cos_bx_div_a;

    // Виведення результатів
    std::cout << "Значення Y: " << Y << std::endl;
    std::cout << "Значення Z: " << Z << std::endl;

    return 0;
}
