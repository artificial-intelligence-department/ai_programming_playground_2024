#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double epsilon = 0.0001;
    double sum = 0.0;
    double a_n = 1.0; 
    int n = 0;

    while (abs(a_n) >= epsilon) { 
        sum += a_n;

        a_n = a_n * (n + 1) / ((2 * n + 1) * (2 * n + 2)); 
        n++;
    }

    cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << endl;
    return 0;
}
