#include <iostream>
#include <cmath>

using namespace std;
//використав дійсну змінну і подвійну дійсну змінну
//також використав математичні операції і вивід 
int main () { 
    float a = 0.5, b = 2.9, x = 0.3;
    double U = (pow(a,3) + exp(-x) * cos(b*x))/(b*x - exp(-x) * sin(b*x) + 1);
    double F = exp(2*x)*log(a+x) - pow(b, 3*x)*log(abs(x-b));
    printf("U = (a^3 + e^(-x) * cos(b*x)/(b*x - e^(-x) * sin(b*x) + 1) = %lf,\n", U); 
    printf("F = e^2x * log(a+x) - b^3x * log|x-b| = %lf, a = %f, b = %f, x = %f.", F, a, b, x);
    return 0;
}