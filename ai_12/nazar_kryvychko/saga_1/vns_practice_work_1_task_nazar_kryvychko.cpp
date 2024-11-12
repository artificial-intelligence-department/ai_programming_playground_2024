#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>

int main(void)
{
    int integerVar = 5;              // Цілочисельна змінна
    float realVar = 2.7f;            // Дійсна змінна
    double doubleVar = 3.14159;      // Дійсна змінна з подвійною точністю
    const int INTEGER_CONST = 10;    // Цілочисельна константа

    double x = 1.45, y = -1.22, z = 3.5;
    double b = (1 + std::pow(z, 2)) / (3 + (std::pow(z, 2) / 5));
    double a;

    // Використання умовного оператора для розгалуження
    if (integerVar > INTEGER_CONST)
    {
        a = (2 * cos(x - (M_PI / 6)) * b) / (0.5 + std::pow(sin(y), 2));
    }
    else
    {
        a = (2 * cos(x + realVar) * b) / (1 + std::pow(sin(y), 2));
    }

    std::cout << "Result -> " << a;

    return 0;
}
