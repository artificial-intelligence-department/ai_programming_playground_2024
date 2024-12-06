#include <iostream>
#include <cmath> 

int main() {
    
    const double a = 0.7;
    const double b = 0.05;
    const double x = 0.5;

  
    double R = (pow(x, 3) * (x + 1)) / pow(b, 2) - pow(sin(x * (x + a)), 2);

    
    double S = sqrt((x * b) / a) + pow(cos(pow(x + b, 3)), 2);

    
    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;

    return 0;
}
