#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double R1, R2;
    cout << "Введіть величину першого опору (Ом) > ";
    cin >> R1;
    cout << "Введіть величину другого опору (Ом) > ";
    cin >> R2;

    if (R1 <= 0 || R2 <= 0) {
        cout << "Помилка: Опір має бути більшим за 0." << endl;
        return 1;
    }

    double R_total = 1 / (1 / R1 + 1 / R2);
    cout << "Опір ланцюга: " << R_total << " Ом" << endl;

    double radius, height;
    cout << "\nВведіть радіус основи конуса > ";
    cin >> radius;
    cout << "Введіть висоту конуса > ";
    cin >> height;

    if (radius <= 0 || height <= 0) {
        cout << "Помилка: Радіус і висота мають бути більшими за 0." << endl;
        return 1;
    }

    double volume = (1.0 / 3) * M_PI * radius * radius * height;
    cout << "Об'єм конуса: " << volume << " куб. од." << endl;

    return 0;
}
