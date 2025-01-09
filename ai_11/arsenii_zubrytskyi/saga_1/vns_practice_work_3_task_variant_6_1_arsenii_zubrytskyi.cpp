#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double pad, hight, area;

    cout << "Обчислення площі трикутника.\n" << "Введіть початкові дані:\n" << "Підстава (см) ";
    cin >> pad;
    cout << "Висота (см) ";
    cin >> hight;

    area = (pad * hight) / 2;

    cout << "Площа трикутника " << area << " кв.см.";
    
    return 0;
}