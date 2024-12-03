#include <iostream>
#include <iomanip>
#include <cmath>
#define pi 3.14
using namespace std;
int main()
{
    double r1, r2, h;
    cout << "Enter r1: ";
    cin >> r1;
    cout << "Enter r2: ";
    cin >> r2;
    cout << "Enter heigth: ";
    cin >> h;
    if (r1 <= 0 || r2 <= 0 || h <= 0 || r1 <= r2)
    {
        cout << "Incorrect values inputed!" << endl;
        return 1;
    }
    double V = pi * h * (r1 * r1 - r2 * r2);
    cout << "V = " << V << endl;
}
