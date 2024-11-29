#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x, y;

    cout << "Table of function values y = 2.6x - 3:\n";
    cout << "-----------------\n";
    cout << "   x    |    y\n";
    cout << "-----------------\n";

    for (x = -2; x <= 2; x += 0.5) {
        y = 2.6 * x - 3;
        cout << setw(6) << x << " | " << setw(6) << y << endl;
    }

    return 0;
}
