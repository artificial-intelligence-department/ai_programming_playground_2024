#include <iostream>
#include <cmath>

int main() {

    double a = 0.7;
    double b = 0.05;
    double x = 0.43;

    double R = (x * x * (x + 1)) / b - pow(sin(x - a), 2);

    double S = sqrt(x * b / a) + fabs(pow(cos(x + b), 3));

    std::cout << "R = " << R << std::endl;
    std::cout << "S = " << S << std::endl;

    return 0;
}
