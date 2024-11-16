#include <iostream>
#include <cmath>
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    double epsilon = 0.0001; 
    double sum = 0.0; 
    int n = 0; 
    double x; 

    do {
        x = factorial(n) / (3 * pow(n, n));
        sum += x;
        n++;
    } while (fabs(x) >= epsilon); 

    std::cout << "Сума ряду з точністю " << epsilon 
    << " дорівнює: " << sum << std::endl;

    return 0;
}
