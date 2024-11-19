#include <iostream>
#include <cmath> 

int main() {
    const double epsilon = 0.0001; 
    const double e = std::exp(1.0); 

    double a_n = 1.0; 
    double sum = a_n; 
    int n = 0;        

    while (a_n >= epsilon) {
        n++;
        a_n *= e * std::pow(100, -2.0 * n + 1); 
        sum += a_n; 
    }

    std::cout << "Сума ряду з точністю " << epsilon << " = " 
              << std::fixed << sum << std::endl;

    return 0;
}
