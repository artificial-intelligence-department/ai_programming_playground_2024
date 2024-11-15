#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

int main() {

    double epsilon = 0.0001;
    double sum = 0.0;
    double term;
    int n = 1; 

    do {
        term = pow(-1, n - 1) / pow(n, n);
        sum += term; 
        n++; 
    } while (abs(term) > epsilon); 

    cout << "Сума ряду з точністю ε = " << epsilon << ": " << setprecision(4) << fixed << sum << endl;

    return 0;
}
