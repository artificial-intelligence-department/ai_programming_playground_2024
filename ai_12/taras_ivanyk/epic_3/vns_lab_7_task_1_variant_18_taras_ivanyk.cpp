#include <iostream>
#include <cstdarg>
#include <climits>

int min(int count, ...) {
    va_list args; //оголошення об'єкта для зберіганння аргументів змінної довжини
    va_start(args, count);

    int minValue = INT_MAX;

    for (int i = 0; i < count; ++i) {
        int num = va_arg(args, int);
        if (num < minValue) {
            minValue = num;
        }
    }

    va_end(args);
    return minValue;
}

int main() {

    int result1 = min(5, 34, 21, 5, 77, 12);
    int result2 = min(10, 56, 23, 5, 89, 12, 8, 9, 0, 44, 33);
    int result3 = min(12, 99, 55, 23, 5, 89, 12, 8, 3, 44, 33, 1, 100);

    std::cout << "Мінімальне значення серед перших 5 чисел: " << result1 << std::endl;
    std::cout << "Мінімальне значення серед перших 10 чисел: " << result2 << std::endl;
    std::cout << "Мінімальне значення серед перших 12 чисел: " << result3 << std::endl;

    return 0;
}
