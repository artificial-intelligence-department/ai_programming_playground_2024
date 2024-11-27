#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double h = 1.0; 

    for (double x = -5.0; x <= 5.0; x += h) {
        double y;

        if (abs(x) <= 3) {
            y = pow(sin(x + 0.4), 2) / (4 * x * x);
        } else {
            y = pow(x, 4) + 2 * x * x * cos(x);
        }

        cout << "Якщо x = " << x << ", то y = " << y << endl;
    }

    return 0;
}

