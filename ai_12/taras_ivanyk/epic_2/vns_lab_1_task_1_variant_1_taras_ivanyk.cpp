#include <iostream>
#include <cmath>

int main() {
    // Обчислення з типом float
    float aF = 1000;
    float bF = 0.0001;
    float numeratorF, enumeratorF, resultF;
    numeratorF = pow(aF - bF, 3) - pow(aF, 3);
    enumeratorF = pow(bF, 3) - 3 * aF * pow(bF, 2) - 3 * pow(aF, 2) * bF;
    resultF = numeratorF / enumeratorF;
    std::cout << "Результат при float = " << resultF << std::endl;

    // Обчислення з типом double
    double aD = 1000;
    double bD = 0.0001;
    double numeratorD, enumeratorD, resultD;
    numeratorD = pow(aD - bD, 3) - pow(aD, 3);
    enumeratorD = pow(bD, 3) - 3 * aD * pow(bD, 2) - 3 * pow(aD, 2) * bD;
    resultD = numeratorD / enumeratorD;
    std::cout << "Результат при double = " << resultD << std::endl;

    return 0;
}
