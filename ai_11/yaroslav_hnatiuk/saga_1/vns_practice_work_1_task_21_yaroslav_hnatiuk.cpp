#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 0.5, b = 3.1, x = 1.4; 

    double alpha = sqrt(abs(a * x * x * sin(2 * x) + exp(-2 * x) * (x + b))); 
    double omega = (1 / (pow(cos(x), 2) * pow(x, 3))) - (x / cbrt(a * a + b * b));

    cout << "Альфа: " << alpha << endl;
    cout << "Омега: " << omega << endl;

    return 0;
}

