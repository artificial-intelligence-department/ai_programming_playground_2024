#include <iostream>
#include <cstdarg>

using namespace std;

int findGCD(int x, int y) {
    while (y != 0) {
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}

// Функція для обчислення НСК двох чиселs
int findLCM(int x, int y) {
    return (x / findGCD(x, y)) * y;
}

// Функція з змінною кількістю параметрів для обчислення НСК кількох чисел
int nok(int numCount, ...) {
    va_list numbers;
    va_start(numbers, numCount);

    int currentLCM = va_arg(numbers, int); // зчитуємо перший аргумент

    for (int i = 1; i < numCount; ++i) {
        int nextNum = va_arg(numbers, int);
        currentLCM = findLCM(currentLCM, nextNum);
    }

    va_end(numbers);
    return currentLCM;
}

int main() {
    // Виклики функції nok з різною кількістю параметрів
    cout << "НСК для чисел 4, 7, 12: " << nok(3, 4, 7, 12) << std::endl;
    cout << "НСК для чисел 1, 2, 3, 5, 7: " << nok(5, 1, 2, 3, 5, 7) << std::endl;
    cout << "НСК для чисел 10, 15, 20, 25, 30, 35: " << nok(6, 10, 15, 20, 25, 30, 35) << std::endl;

    return 0;
}