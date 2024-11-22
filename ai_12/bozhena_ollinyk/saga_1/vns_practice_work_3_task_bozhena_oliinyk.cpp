#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;
 
int main()
{
    ofstream vFile("Volume.txt");
    if (vFile.is_open())
    {
        vFile << "Обчислення об'єму паралелепіпеда." << endl;
        vFile.close();
    }

    ifstream inputFile("Volume.txt");
    if (inputFile.is_open())
    {
        string vString;
        getline(inputFile, vString);
        cout << vString << endl;

        inputFile.close();
    }
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

    const int gToK = 1000;

    grams = pound * 405.9;
    kilos = grams / gToK;

    cout << pound << " фунтів дорівнюють " << kilos << " кілограмам" << endl;

    return 0;
}
