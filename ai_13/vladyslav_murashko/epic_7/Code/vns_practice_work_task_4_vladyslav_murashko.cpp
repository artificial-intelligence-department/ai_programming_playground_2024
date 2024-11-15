#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int size = 10;
    int* numbers = new int[size]; // вказівник для створення динамічного масиву
    int sum = 0;

    std::cout << "Generated numbers: ";
    for (int i = 0; i < size; ++i) {
        numbers[i] = std::rand() % 10 + 1;
        std::cout << numbers[i] << " ";
        sum += numbers[i];
    }

    double average = (double)(sum) / size;
    std::cout << "\nAverage number: " << std::fixed << std::setprecision(2) << average << std::endl;

    delete[] numbers;
    return 0;
}
