#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, x, y, hx, ha;
    hx = 0.5;
    ha = 1;

    for (a = 2; a <= 10; a += ha) 
    {
        for (x = 1; x <= 8; x += hx) 
        {
            if (a > x) {
                y = pow(a, 2) + x;
            } 
            else if (a == x) {
                y = pow(a, 2);
            } 
            else {
                y = pow(a, 2) - x;
            }
            //Використав умовні оператори та розгалуження, щоб обчислити функції з кількома умовами
            cout << "a = " << a << ", x = " << x << ", y = " << y << endl;
            cout << "-------------------------" << endl;
        }
    }

    return 0;
}