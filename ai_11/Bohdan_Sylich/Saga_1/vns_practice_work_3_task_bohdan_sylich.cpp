#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double length, width, height, weightPounds;
    
    cout << "Обчислення об'єму паралелепіпеда.\n";
    cout << "Введіть початкові дані:\n";
    
    cout << "Довжина (см) > ";
    cin >> length;
    
    cout << "Ширина (см) > ";
    cin >> width;
    
    cout << "Висота (см) > ";
    cin >> height;
    

    double volume = length * width * height;
    

    cout << fixed << setprecision(2);
    cout << "Об'єм: " << volume << " куб.см.\n";


    cout << "\nПерерахунок ваги:\n";
    cout << "Введіть вагу в фунтах > ";
    cin >> weightPounds;

    double weightKilograms = (weightPounds * 405.9) / 1000;


    cout << "Вага: " << weightKilograms << " кг.\n";

    return 0;
}
