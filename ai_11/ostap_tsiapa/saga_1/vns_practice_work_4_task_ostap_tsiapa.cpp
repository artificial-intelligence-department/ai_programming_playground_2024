#include <iostream>
#include <iomanip>

int main() {
    // Массив перших п'яти цілих позитивних непарних чисел
    int oddNumbers[] = {1, 3, 5, 7, 9};
    
    std::cout << std::setw(10) << "Number" << std::setw(10) << "Square" << std::endl;
    std::cout << "=========================" << std::endl;

    for(int i = 0; i < 5; ++i) {
        int number = oddNumbers[i];
        int square = number * number;
        std::cout << std::setw(10) << number << std::setw(10) << square << std::endl;
    }

    return 0;
}
