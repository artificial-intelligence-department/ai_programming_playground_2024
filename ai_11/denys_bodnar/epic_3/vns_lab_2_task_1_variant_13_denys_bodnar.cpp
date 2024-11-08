#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    const double e = 0.0001;
    double sum = 0;
    int n = 0;

    while (true) {
        double s = pow(3, n) * factorial(n) / factorial(3 * n);

        sum = sum + s;

        if (s < e) {
            break;
        }

        n++;
    }

    cout << "Сума ряду з точністю epsilon = " << e << " дорівнює: " << sum << endl;

    return 0;
}
