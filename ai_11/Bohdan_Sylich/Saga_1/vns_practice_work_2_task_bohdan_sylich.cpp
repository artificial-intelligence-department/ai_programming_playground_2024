#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 5.3, y = 1.1, hx = 0.5;
    double x_start = -3.0, x_end = 3.0;

    cout << "x\t\tCondition\t\tResult (y)" << endl;
    cout << "-------------------------------------------" << endl;

    for (double x = x_start; x <= x_end; x += hx) {
        double result;
        double condition = x * x + y * y;

        if (condition <= a * a) {
            result = x / (15 * x * x);
            cout << x << "\t\t<= a^2\t\t" << result << endl;
        } else {
            result = x * x / (x * x + exp(x));
            cout << x << "\t\t> a^2\t\t" << result << endl;
        }
    }

    return 0;
}
