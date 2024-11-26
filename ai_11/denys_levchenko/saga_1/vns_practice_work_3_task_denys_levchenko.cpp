#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
struct Parallelepiped {
    double length;
    double width;
    double height;
};

struct ShoppingCart {
    double tomatoesPrice;
    double cucumbersPrice;
    int dillBunches;
    int tomatoes;
    int cucumbers;
    double dillPricePerBunch;
};

double calculateVolume(const Parallelepiped* p) {
    return p->length * p->width * p->height;
}

double calculateTotalCost(const ShoppingCart* cart) {
    return cart->tomatoesPrice * cart->tomatoes + cart->cucumbersPrice * cart->cucumbers + cart->dillPricePerBunch * cart->dillBunches;
}

int main() {
    // Файли для запису і зчитування
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    if (!outFile || !inFile) {
        std::cerr << "Помилка відкриття файлу!" << std::endl;
        return 1;
    }

        std::cout << "Обчислення об'єму паралелепіпеда.\n";
        std::cout << "Введіть в одному рядку довжину, ширину і висоту паралелепіпеда (в сантиметрах).\n";
        std::cout << "Числа розділяйте пропусками: ";

    Parallelepiped p;
    std::cin >> p.length >> p.width >> p.height; 


    double volume = calculateVolume(&p);
    std::cout << "Об'єм паралелепіпеда: " << std::fixed << std::setprecision(2) << volume << " см.куб." << std::endl;

    outFile << "Об'єм паралелепіпеда: " << std::fixed << std::setprecision(2) << volume << " см.куб." << std::endl;

    std::cout << "\nОбчислення вартості покупки.\n";

    ShoppingCart cart;

    do {
        std::cout << "Введіть кількість помідорів: ";
        std::cin >> cart.tomatoes;

        if (cart.tomatoes < 0) {
            std::cout << "Кількість не може бути від'ємною. Спробуйте ще раз.\n";
            continue;
        }

        inFile >> cart.tomatoesPrice;



        std::cout << "Введіть кількість огірків: ";
        std::cin >> cart.cucumbers;

        if (cart.cucumbers < 0) {
            std::cout << "Кількість не може бути від'ємною. Спробуйте ще раз.\n";
            continue;
        }
        inFile >> cart.cucumbersPrice;

        std::cout << "Введіть кількість пучків кропу: ";
        std::cin >> cart.dillBunches;

        if (cart.dillBunches < 0) {
            std::cout << "Кількість пучків не може бути від'ємною. Спробуйте ще раз.\n";
            continue;
        }
        inFile >> cart.dillPricePerBunch;

    } while (cart.tomatoes < 0 || cart.cucumbers < 0 || cart.dillBunches < 0);

    double totalCost = calculateTotalCost(&cart);

    std::cout << "Загальна вартість покупки: " << std::fixed << std::setprecision(2) << totalCost << " грн.\n";

    outFile << "Загальна вартість покупки: " << std::fixed << std::setprecision(2) << totalCost << " грн.\n";


    return 0;
}
