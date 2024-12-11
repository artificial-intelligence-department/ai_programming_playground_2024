#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double coefficientA = 5, coefficientB = 3, stepSize = 0.1, rangeStart = 1, rangeEnd = 2;
    double conditionThreshold = coefficientA / coefficientB;

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "x\t\ty\n";

    for (double currentX = rangeStart; currentX <= rangeEnd; currentX += stepSize) {
        double resultY;
        if (fabs(currentX) < conditionThreshold) {
            resultY = sin(fabs(coefficientA * currentX + coefficientB));
        } else {
            resultY = cos(fabs(coefficientA * currentX - coefficientB));
        }
        std::cout << currentX << "\t" << resultY << "\n";
    }

    return 0;
}