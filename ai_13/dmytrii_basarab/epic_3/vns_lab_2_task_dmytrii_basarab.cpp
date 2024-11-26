#include <iostream>
#include <stdio.h>
#include <cmath>

const double e = 2.71828;

int main() {
    double result;
    double sum = 0;
    for (int n=1; result < 0.0001 ;n++) {
        result = pow(e, n)*pow(100, -pow(n, 2));
        sum += result; 
    }

    std::cout << sum << std::endl;
    return 0;
}