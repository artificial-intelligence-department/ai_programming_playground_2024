#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a, x, y, hx, ha; /*використано тип float, 
    тому що згідно умови ми розуміємо, що жодне із значень не буде мати більше, ніж 1 знак після коми*/
    hx = 0.5;
    ha = 1;


    for (a = 2; a <= 10; a += ha) {
        for (x = 1; x <= 8; x += hx) {
            if (a > x) {
                y = pow(a, 2) + x;
            } else if (a == x) {
                y = pow(a, 2);
            } else {
                y = pow(a, 2) - x;
            }
            /*в коді використані умовні оператори та розгалуження для того, щоб обчислити функції з кількома умовами(3)*/
            cout << "a = " << a << ", x = " << x << ", \t y = " << y << endl;
        }
    }

    return 0;
}
