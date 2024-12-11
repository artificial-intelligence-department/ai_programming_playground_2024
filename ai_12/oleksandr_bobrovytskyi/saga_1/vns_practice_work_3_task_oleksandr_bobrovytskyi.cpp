#include<bits/stdc++.h>

using namespace std;

int main()
{   
    double length, width, hight, km;
    cout << "Обчислення площі поверхні паралелепіпеда\nВведіть початкові дані: \n";
    cout << "Довжина (см) - ";
    cin >> length;
    cout << "Ширина(см) - ";
    cin >> width;
    cout << "Висота(см) - ";
    cin >> hight;

    cout << "Площа поверхні: " << 2*(length + width) * hight + 2*(length * width)<< " кв.см.\n";
    
    cout << "Введіть відстань в кілометрах - ";
    cin >> km;

    cout << "Ця відстань в верстах - " << km / 1.0668;

    return 0;
}