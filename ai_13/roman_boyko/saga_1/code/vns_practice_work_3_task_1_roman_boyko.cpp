#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double vnesok, percent;
    int time;
    cout << "Величина внеску (грн.) > 2500: ";
    cin >> vnesok;
    cout << "Термін внеску (днів) > 30: ";
    cin >> time;
    cout << "Процентна ставка (річних в %) > 20%: ";
    cin >> percent;
    if (vnesok <= 2500 || time <= 30 || percent <= 20)
    {
        cout << "Incorrect value entered!";
        return 1;
    }
    double prof = (vnesok * time * percent) / (365 * 100);
    cout << "profit: " << fixed << setprecision(2) << prof << endl;
    double sum = vnesok + prof;
    cout << "sum: " << fixed << setprecision(2) << sum << endl;
}
