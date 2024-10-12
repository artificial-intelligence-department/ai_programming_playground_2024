#include <iostream>
#include <math.h>

using namespace std;

int main() {

    cout << "Quadratic" << endl;

    int a, b, c;
    do {
        cout << "Enter a: " << endl;
        cin >> a;
        if (a != 0) {
            cout << "Your a: " << a << endl;
        }
    } while (a == 0);

    do {
        cout << "Enter b: " << endl;
        cin >> b;
        if (b != 0) {
            cout << "Your b: " << b << endl;
        }
    } while (b == 0);

    do {
        cout << "Enter c: " << endl;
        cin >> c;
        if (c != 0) {
            cout << "Your c: " << c << endl;
        }
    } while (c == 0);


    int D = b * b - 4 * a * c;

    cout << "Your discriminant: " << D << endl;


    if (D > 0) {
        int x1 = (-b + sqrt(D) / (2 * a));
        int x2 = (-b - sqrt(D) / (2 * a));


        cout << "x1 = " << x1 << "x2 = " << x2 << endl;
    }
    else if (D == 0) {

        int x = -b / (2 * a);

        cout << "x = " << x << endl;

    }
    else {
        cout << "Error!" << endl;

    }
    return 0;
}