#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    cout << "Обчислення об'єму паралелепіпеда." << endl;
    cout << "Введіть початкові дані:" << endl;

    double length, width, height, volume;
    cout << "Довжина (см) = ";
    cin >> length;
    cout << "Ширина(см) = ";
    cin >> width;
    cout << "Висота(см) = ";
    cin >> height;

    volume = length * width * height;

    cout << fixed << setprecision(2); 
    cout << "Об'єм: " << volume << " куб.см." << endl;

    double pound, kilos, grams;
    cout << "Введіть вагу у фунтах: ";
    cin >> pound;

    grams = pound * 405.9;
    kilos = grams / 1000;

    cout << pound <<  " фунтів дорівнюють " << kilos << " кілограмам" << endl;

    return 0;
}
