// var 8
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double R1, R2, R_total;
    cout << "Введіть величину першого опору (Ом) > ";
    cin >> R1;
    cout << "Введіть величину другого опору (Ом) > ";
    cin >> R2;
    
    R_total = 1 / ((1 / R1) + (1 / R2));
    cout << "Опір ланцюга: " << R_total << " Ом" << endl;

    double r, h, volume;
    cout << "Введіть радіус основи конуса (см): ";
    cin >> r;
    cout << "Введіть висоту конуса (см): ";
    cin >> h;
    
    volume = (1.0 / 3.0) * M_PI * pow(r, 2) * h;
    cout << "Об'єм конуса: " << volume << " см^3" << endl;
}
