#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double r, h, v;
    cout << "Обчислення об'єму циліндра." << endl << "Введіть початкові дані:" << endl << "Радіус підстави (см) > ";
    cin >> r;
    cout << "Висота циліндра (см) > ";
    cin >> h;
    v = M_PI * pow(r, 2) * h;
    cout << "Об'єм " << v << " см.куб.";
    return 0;
}