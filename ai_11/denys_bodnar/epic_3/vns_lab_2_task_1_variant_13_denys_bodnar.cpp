#include <iostream>
#include <cmath>

using namespace std;

namespace myfun {
    double factorial(int n) {
        if (n <= 1) {
            return 1;
        }
        return n * factorial(n - 1);
    }
}

int main() {
    const double e = 0.0001;
    double sum = 0;
    int n = 0;

    while (true) {
        double s = pow(3, n) * myfun::factorial(n) / myfun::factorial(3 * n);

        sum += s;

        if (s < e) {
            break;
        }

        n++;
    }

    cout << "Сума ряду з точністю epsilon = " << e << " дорівнює: " << sum << endl;

    return 0;
}
