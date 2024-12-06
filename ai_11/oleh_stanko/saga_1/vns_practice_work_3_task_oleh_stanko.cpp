// var 13
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double R, H, S, V;
    cout << "Обчислення об'єму циліндра.\n";
    cout << "Введіть початкові дані:\n";
    cout << "Радіус підстави (см) > ";
    cin >> R;
    cout << "Висота циліндра (см) > ";
    cin >> H;
    S = M_PI * R * R;
    V = S * H;
    cout << "Об'єм " << V << " см.куб";

}