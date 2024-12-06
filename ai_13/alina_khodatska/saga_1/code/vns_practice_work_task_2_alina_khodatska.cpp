#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x_start = 0.0;
    double x_end = 3.5;
    double step = 0.1;

    int negativeCount = 0;

    for (double x = x_start; x <= x_end; x += step) {
        double y = cos(pow(x, 2)) * exp(-x);

        if (y < 0) {
            negativeCount++;
        }
    }

    cout << "Number of times the function is negative: " << negativeCount << endl;

    return 0;
}
