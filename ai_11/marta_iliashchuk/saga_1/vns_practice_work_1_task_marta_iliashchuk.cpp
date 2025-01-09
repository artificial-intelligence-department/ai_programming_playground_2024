#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 10.2;
    double b = 9.3;
    double x = 2.4;
    double c = 0.5;

    double K = log(a + pow(x, 3)) + pow(sin(x / b), 2);

    double numerator = x + cbrt(x + a); 
    double denominator = x - sqrt(fabs(x - b)); 
    double M = exp(-c * x) * (numerator / denominator);
    
    cout << "K = " << K <<endl;
    cout << "M = " << M <<endl;

    return 0;
}