#include <iostream>
#include <cmath>

using namespace std;



double f(int n) {
    double r = 1;
    for (int i = 1; i <= n; ++i) {
        r *= i;
    }
    return r;
}

int main() {

    double suma = 0.0;

    for (int n = 1; n <= 10; ++n) {

        double suma = f(n) / pow(n, sqrt(n));
    }

    cout << suma << endl;

    return 0;
}
