#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    std::string minNumber = s;
    std::string maxNumber = s;

    // Обчислення мінімального числа
    for (size_t i = 0; i < s.size(); ++i) {
        if (minNumber[i] == '*') {
            if (i == 0) {
                minNumber[i] = '1'; // Перший символ не може бути 0
            }
            else {
                minNumber[i] = '0';
            }
        }
    }

    // Обчислення максимального числа
    for (size_t i = 0; i < s.size(); ++i) {
        if (maxNumber[i] == '*') {
            maxNumber[i] = '9';
        }
    }

    // Виведення результатів
    std::cout << minNumber << " " << maxNumber << std::endl;

    return 0;
}
