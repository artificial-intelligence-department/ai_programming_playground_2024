#include <iostream>
#include <complex>

using namespace std;

int multiply(int n, int k);
double multiply(double n, double k);
complex<double> multiply(complex<double> n, complex<double> k);

int main() {
    cout << multiply(2, 5) << endl;
    cout << multiply(2.0, 5.0) << endl;
    
    complex<double> z1(3.0, 4.0);
    complex<double> z2(1.0, 2.0);
    cout << multiply(z1, z1);

    return 0;
}

int multiply(int n, int k) {
    return n * k;
}

double multiply(double n, double k) {
    return n * k;
} 

complex<double> multiply(complex<double> n, complex<double> k) {
    return n * k;
}

