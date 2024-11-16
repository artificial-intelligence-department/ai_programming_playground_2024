#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0.1;
    double x = a;
    double eps = 0.0001;
    double b = 1.0;
    double step = (b - a) / 10.0;

    for (; x <= b; x += step) {
        double sn = 1.0 + 2.0 * x;
        double se = sn;

        for (int n = 3; n < 20; ++n) {
            double el = pow(2 * x, n) / tgamma(n + 1.0);
            sn += el;
        }

        double elem = 1.0;
        for (int k = 3; elem >= eps; ++k) {
            elem = pow(2.0*x, k) / tgamma(k + 1);
            se += elem;
        }

        cout << "X = " << x << ":  SN = " << sn << ",   SE = " << se << ",   Y = e ^ (2x)" << endl;
    }
    
    return 0;
}
