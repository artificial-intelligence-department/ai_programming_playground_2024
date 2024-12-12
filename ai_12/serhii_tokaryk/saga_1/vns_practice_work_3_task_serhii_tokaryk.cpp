#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a , b , h , S; 
    cout << "Обчислення площі поверхні паралелепіпеда." << endl;
    cout << "Введіть початкові дані:" << endl;

    cout << "Довжина(см): ";
    cin >> a;
    cout << endl;

    cout << "Ширина(см): ";
    cin >> b;
    cout << endl;

    cout << "Висота(см): ";
    cin >> h;
    cout << endl;

    S = 2*(a*b + a*h + b*h);
    cout << fixed << setprecision(2); 
    cout << "Площа поверхні: " << S << " кв.см." << endl;


    
    const double METERS_IN_KILOMETER = 1000.0;   
    const double METERS_IN_VERSTA = 1066.8;     

    double kilometers;
    cout << "Введіть відстань у кілометрах: ";
    cin >> kilometers;

    double versts = (kilometers * METERS_IN_KILOMETER) / METERS_IN_VERSTA;

    cout << "Відстань у верстах: " << versts << endl;

    return 0;
}