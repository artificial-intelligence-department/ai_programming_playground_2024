#include <iostream>
#include <iomanip>
#include <cmath>

double calculate(double x) {
    return -2.4 * x + 5 * x - 3;
}

void fillXArray(double* xArray, int size, double start, double step, int index = 0) {
    if (index >= size) return;
    xArray[index] = start + index * step; 
    fillXArray(xArray, size, start, step, index + 1); 
}
void fillXArray(double xArray[], double xyArray[][2], int size, int index = 0) {
    if (index >= size) return;
    xyArray[index][0] = xArray[index];            
    xyArray[index][1] = calculate(xArray[index]); 
    fillXArray(xArray, xyArray, size, index + 1); 
}

int main() {
    double start = -2.0, end = 2.0, step = 0.5;
    int size = static_cast<int>((end - start) / step) + 1;

    double xArray[size]; // Одновимірний масив
    double xyArray[size][2]; // Двовимірний масив

    fillXArray(xArray, size, start, step);

    fillXArray(xArray, xyArray, size);

    std::cout << std::setw(5) << "x" << std::setw(10) << "y" << std::endl;
    std::cout << "------------------\n";

    int i = 0;
    while (i < size) {
        std::cout << std::setw(5) << xyArray[i][0] << std::setw(10) << xyArray[i][1] << std::endl;
        i++;
    }

    return 0;
}
