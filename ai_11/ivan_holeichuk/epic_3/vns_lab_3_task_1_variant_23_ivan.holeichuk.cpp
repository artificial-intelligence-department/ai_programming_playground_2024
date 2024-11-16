#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    double a = 0.1, b = 1.0;

    int k = 10;

    double D = (b - a) / k;


    cout << " y = 2 * (cos^2(x) - 1):" << endl;


    for (double x = a; x <= b; x += D) {
        
        double y = 2 * (pow(cos(x), 2) - 1);

        cout << "x = " << x << endl;
        cout << " y = " << y << endl;
    }

    return 0;
}
