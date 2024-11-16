#include <iostream>
#include <complex>
using namespace std;

double subtract(double a, double b) {
    return a - b;
}

complex<double> subtract(complex<double> a, complex<double> b) {
    return a - b;
}

int main() {
    double num1 = 19.9, num2 = 9.9;
    cout << "Result of subtracting real numbers: " << subtract(num1, num2) << endl;

    complex<double> num3(5.4, 4.0);  
    complex<double> num4(3.9, 2.2);  
    complex<double> result = subtract(num3, num4);
    cout << "Result of subtracting complex numbers: " << result << endl;

    return 0;
}
