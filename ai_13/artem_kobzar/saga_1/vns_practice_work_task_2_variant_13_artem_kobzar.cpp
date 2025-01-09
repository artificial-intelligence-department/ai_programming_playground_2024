#include <iostream>
#include <cmath> 

using namespace std;

int main() {
    double a = 1.7, b = 2.3;
    double hx = 0.9, hy = 1.0;
    double x0 = -1, xn = 1;
    double y0 = -2, yn = 2;

    for (double x = x0; x <= xn; x += hx) {
        for (double y = y0; y <= yn; y += hy) {
            double z;

            if (x * y > 0) {
                z = log(sqrt(a * pow(x, 2) + b * pow(y, 3)));
            } else {
                z = pow(a, x) + pow(b, y);
            }

       cout << "x equals: "<< x <<endl<<"y equals: "<< y <<endl<<"z equals: "<< z <<endl;
        }
    }
    return 0;
}
