#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x = 0;
    double h = 0.31;
    double y;
   
    const int a = 2;
    const int b = 3;
    const int c = 7;

    do {
        if (x < 2) {
            y = pow(a, b - x) + c;
        } else if (x >= 2 && x <= 4) {
            y = pow(b, c - x) + a;
        } else {
            y = pow(c, a - x) + b;
        }
        cout << "x = " << x << ", y = " << y << endl;
        x += h;
    } while (x <= 5);

  return 0;
}
