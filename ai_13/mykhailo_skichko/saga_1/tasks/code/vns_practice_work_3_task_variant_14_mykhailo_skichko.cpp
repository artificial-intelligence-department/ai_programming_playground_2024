#include <iostream>

int main() {
    double r1, r2, r3;

    std::cout << "\nОбчислення опору електричного ланцюгу із 3-ох послідовно сполучених резисторів.\n";
    std::cout << "Введіть опір кожного резистора:\n";

    std::cout << "Резистор R1 (Ом) > ";
    std::cin >> r1;

    std::cout << "Резистор R2 (Ом) > ";
    std::cin >> r2;

    std::cout << "Резистор R3 (Ом) > ";
    std::cin >> r3;

    double totalResistance = r1 + r2 + r3;

    std::cout << "Загальний опір " << totalResistance << " Ом.\n";

    return 0;
}
