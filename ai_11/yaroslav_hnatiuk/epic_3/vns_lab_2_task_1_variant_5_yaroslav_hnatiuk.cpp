#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double s = 0.0;
    int n = 1;

    while (true) {
        double a_n = pow(-1, n - 1) / pow(n, n);
        s += a_n;
        if (fabs(a_n) < 0.0001) {
            break;
        }

        n++;
    }

    cout << s;
    return 0;
}

