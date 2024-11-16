#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double epsilon = 0.0001;
    double sum = 0.0;
    int n = 1;
    
    while (true) {

        double factorial = 1.0;
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }

        double an = factorial / (3 * pow(n, n));
        
        sum += an;

        if (abs(an) < epsilon) {
            break;
        }
        
        n++;
    }
    
    cout << "Сума ряду з точністю ε=0.0001 = " << sum;

    return 0;
}