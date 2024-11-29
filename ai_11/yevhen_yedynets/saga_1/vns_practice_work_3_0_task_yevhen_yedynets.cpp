#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double voltage, resistance, current;

    cout << "Введіть початкові дані:" << endl;
    cout << "Напруга (вольт) > ";
    cin >> voltage;
    cout << "Опір (Ом) > ";
    cin >> resistance;

    current = voltage / resistance;

    cout << fixed << setprecision(3);
    cout << "Сила струму: " << current << " Ампер" << endl;

    return 0;
}
