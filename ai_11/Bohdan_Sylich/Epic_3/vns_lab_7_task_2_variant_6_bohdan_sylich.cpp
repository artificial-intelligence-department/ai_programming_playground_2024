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
    double real1 = 7.5, real2 = 3.2;
    cout << "Віднімання дійсних чисел: " << real1 << " - " << real2 << " = " << subtract(real1, real2) << endl;

    complex<double> complex1(4.0, 5.0);
    complex<double> complex2(2.0, 3.0);
    complex<double> result = subtract(complex1, complex2);

    cout << "Віднімання комплексних чисел: (" << complex1 << ") - (" << complex2 << ") = (" << result << ")\n";

    return 0;
}