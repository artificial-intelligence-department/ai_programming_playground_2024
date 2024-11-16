#include <iostream>
#include <cmath>


double factorial(int n) {
    if (n <= 1) {
        return 1.0; 
    }
    return n * factorial(n - 1); 
}


double factorial(double x) {
  
    if (x <= 1.0) {
        return 1.0;
    }
    return tgamma(x + 1); 
}

int main() {
    const double epsilon = 0.0001;
    double sum = 0.0;
    double term;
    int n = 0;

    do {
        double numerator = pow(3, n) * factorial(n);    
        double denominator = factorial(3 * n);         
        term = numerator / denominator;
        sum += term;
        ++n;
    } while (fabs(term) >= epsilon);

    std::cout << "Сума ряду з точністю " << epsilon << " дорівнює: " << sum << std::endl;

    return 0;
}
