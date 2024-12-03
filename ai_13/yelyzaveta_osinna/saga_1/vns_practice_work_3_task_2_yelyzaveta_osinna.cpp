#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double pi = 3.14159265358979323846;

    double r;
    cout << "Введіть r: ";
    cin >> r;

    double V = (3*pi*r*r*r)/4;
    double S = 4*pi*r*r;

    cout << "Об'єм кулі V = " << fixed << setprecision(2) << V << endl;
    cout << "Площа поверхні кулі S = " << fixed << setprecision(2) << S << endl;    

    return 0;
}