#include <iostream>
#include <iomanip>

int main() {
    double x, y;
    double start = -4.0;
    double end = 4.0;
    double step = 0.5;

    std::cout << "Таблиця значень функції y = 2x^2 - 5x - 8\n";
	std::cout << "   ( на проміжку [-4; 4] з кроком 0.5 )  \n";
    std::cout << "-----------------------------------------\n";
    std::cout << std::setw(10) << "x" << std::setw(15) << "y\n";
    std::cout << "-----------------------------------------\n";

    for (x = start; x <= end; x += step) {
        y = 2 * x * x - 5 * x - 8;
        std::cout << std::fixed << std::setprecision(1)
                  << std::setw(10) << x << std::setw(15) << y << '\n';
    }

    return 0;
}
