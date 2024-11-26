#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Введіть початкові дані:\n";

    double Op1, Op2;
    cout << "Величина першого опору (Ом): ";
    cin >> Op1;
    cout << "Величина другого опору (Ом): ";
    cin >> Op2;

    double Op_total = Op1 + Op2;
    cout << fixed << setprecision(2);
    cout << "Опір ланцюга: " << Op_total << " Ом\n\n";


    cout << "Банк Альфа-омега\n";

    double deposit;
    const double rate = 0.03;

    cout << "Введіть початковий внесок: ";
    cin >> deposit;

    deposit += deposit * rate;
    deposit += deposit * rate;

    cout << fixed << setprecision(2);
    cout << "Внесок після 2 років: " << deposit << " грн";

    return 0;
}