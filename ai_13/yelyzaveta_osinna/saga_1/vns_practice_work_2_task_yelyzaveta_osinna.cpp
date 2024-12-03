#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x;
    double a = -0.3;

    double hx = 0.5;
    double ha = 0.2;
    const double epsilon = 1e-6;

    for (x = 1; x <= 4; x += hx) {
    
        if (abs(x - 2) < epsilon) { 
            cout << "x = " << x << ", a = " << a << ": Знаменник дорівнює 0" << endl;
            
        } else if (x - 1.5 < 0) {
            cout << "x = " << x << ", a = " << a << ": Підкореневий вираз менший 0" << endl;
            
        } else {
            double z = (sqrt(x - 1.5) + pow(x, a)) / cbrt(x - 2);
            cout << "x = " << x << ", a = " << a << ": z = " << z << endl;
            
        }
        a += ha;
    }

    return 0;
}
