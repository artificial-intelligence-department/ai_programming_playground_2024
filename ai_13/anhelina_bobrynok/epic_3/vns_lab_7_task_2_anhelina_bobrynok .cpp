#include <iostream>
#include <complex>

using namespace std;

int multiply(int a, int b) {
    return a * b;
}

complex<double> multiply(complex<double> a, complex<double> b) {
    return a * b;
}

int main() {
    int intResult = multiply(5, 4);
    cout << "Множення цілих чисел 5 * 4 = " << intResult << endl;

    complex<double> complex1(3.0, 2.0); // Комплексне число 3 + 2i
    complex<double> complex2(1.0, 4.0); // Комплексне число 1 + 4i

    complex<double> complexResult = multiply(complex1, complex2);
    cout << "Множення комплексних чисел (3 + 2i) * (1 + 4i) = "
         << complexResult << endl;

    return 0;
}
