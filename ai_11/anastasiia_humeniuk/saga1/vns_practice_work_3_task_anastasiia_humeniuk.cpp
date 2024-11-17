#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << "Введіть початкові дані:\n";

    double R1, R2;
    cout << "Величина першого опору (Ом) ";
    cin >> R1;
    cout << "Величина другого опору (Ом) ";
    cin >> R2;

    double R_total = R1 + R2;

    cout << fixed << setprecision(2);
    cout << "Опір ланцюга: " << R_total << " Ом" << endl;

    cout << "----Банк Альфа-омега----" << endl;

    double deposit;
    const double rate = 0.03;

    cout << "Введіть початковий внесок: ";
    cin >> deposit;

    deposit += deposit * rate;//1 рік

    deposit += deposit * rate;//2 рік

    cout << fixed << setprecision(2);
    cout << "Сума внеску після 2 років: " << deposit << " грн" << endl;

    return 0;
}
