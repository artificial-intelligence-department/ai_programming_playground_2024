// Варіант - 2
#include <iostream>

using namespace std;

double Area(double length, double width, double height)
{
    return 2*(length * width + length * height + width * height);
}

double ConvertToVerst(double km)
{
    double m = km * 1000;
    
    return m / 1066.8;
}

int main()
{
    double length, width, height;

    cout << "Обчислення площі поверхні паралелепіпеда" << endl;
    cout << "Введіть початкові дані:" << endl;
    cout << "Довжина (см) > ";
    cin >> length;
    cout << "Ширина (см) > ";
    cin >> width;
    cout << "Висота (см) > ";
    cin >> height;
    cout << "Площа поверхні: " << Area(length, width, height) << " кв.см." << endl;
    cout << endl;



    double km;
    cout << "Перерахунок відстані з кілометрів у версти:" << endl;
    cout << "Довжина (км) > ";
    cin >> km;
    cout << "Довжина у верстах: " << ConvertToVerst(km) << endl;

    
    return 0;
}