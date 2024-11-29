#include <iostream>
using namespace std;

int main() {
    double y;
    double hx = 0.5, ha = 1.0;

    for (double a = 2; a <= 10; a += ha) {
        for (double x = 1; x <= 8; x += hx) {
            if (a > x) {
                y = a * a + x;
            } else if (a == x) {
                y = a * a;
            } else {
                y = a * a - x;
            }
        }
    }
    cout<<y<<endl;
    return 0;
}