#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double x_start = 0.0;
    double x_end = 3.5;
    unsigned negative_count = 0;

    for (double x = x_start; x <= x_end; x += 0.1) {
        double y = cos(x * x) * exp(-x);
        if (y < 0) {
            negative_count++;
        }
    }

    cout << "Кількість від'ємних значень функції: " << negative_count << endl;

    return 0;
}
