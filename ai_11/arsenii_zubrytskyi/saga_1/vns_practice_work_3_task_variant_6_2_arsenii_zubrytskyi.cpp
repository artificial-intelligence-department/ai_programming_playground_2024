#include <iostream>
using namespace std;

int main() {
    double KOL;
    cout << "Enter the number of discs produced per hour: ";
    cin >> KOL;

    double shift = KOL * 7;

    double day = KOL * 7 * 2;

    double month = KOL * 7 * 2 * 26;

    cout << "Discs produced in one 8-hour shift: " << shift << endl;
    cout << "Discs produced in one working day: " << day << endl;
    cout << "Discs produced in one month: " << month << endl;

    return 0;
}
