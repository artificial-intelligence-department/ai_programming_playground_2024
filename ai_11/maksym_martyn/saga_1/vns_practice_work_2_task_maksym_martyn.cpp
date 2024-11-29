#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double x_start = 1.0, x_end = 3.0, hx = 0.1;
    int a_start = 1, a_end = 5;
    const double b = 2.0;

    for (int a = a_start; a <= a_end; ++a) {
        cout << "Result for a = " << a << ":\n";
        
        for (double x = x_start; x <= x_end; x += hx) {
            double y;
            if (x < b) {
                y = sin(abs(a * x + pow(b, a)));
            } else {
                y = cos(abs(a * x - pow(b, a)));
            }
            cout << "x = " << fixed << setprecision(1) << x 
                 << ", y = " << fixed << setprecision(5) << y << endl;
        }
        cout << endl;
    }

    return 0;
}
