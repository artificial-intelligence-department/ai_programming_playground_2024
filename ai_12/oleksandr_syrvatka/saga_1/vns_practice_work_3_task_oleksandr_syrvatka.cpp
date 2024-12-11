#include <iostream>
using namespace std;

int main() {
    // Перше завдання: обчислення об'єму паралелепіпеда
    double length, width, height, volume;

    cout << "Обчислення об'єму паралелепіпеда." << endl;
    cout << "Введіть початкові дані:" << endl;

    // Введення довжини, ширини і висоти
    cout << "Довжина (см) > ";
    cin >> length;
    cout << "Ширина (см) > ";
    cin >> width;
    cout << "Висота (см) > ";
    cin >> height;

    volume = length * width * height;

    cout << "Об'єм: " << volume << " куб. см." << endl;

    // Друге завдання: перерахунок ваги з фунтів у кілограми
    double pounds, kilograms;

    cout << "\nПерерахунок ваги з фунтів у кілограми." << endl;
    cout << "Введіть вагу у фунтах > ";
    cin >> pounds;

    kilograms = pounds * 0.4059;

    cout << "Вага у кілограмах: " << kilograms << " кг." << endl;

    return 0;
}
