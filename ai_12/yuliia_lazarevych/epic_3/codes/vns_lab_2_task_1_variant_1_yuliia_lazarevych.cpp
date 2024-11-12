#include <iostream>
using namespace std;

int main() {
    const double epsilon = 0.0001;
    double sum = 0.0;
    double term = 1.0; 
    int n = 0;

    while (term >= epsilon) {
        sum += term;
        ++n;
        term = term * static_cast<double>(n) / (2 * n * (2 * n - 1));
    }

    cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << endl;
    return 0;
}
