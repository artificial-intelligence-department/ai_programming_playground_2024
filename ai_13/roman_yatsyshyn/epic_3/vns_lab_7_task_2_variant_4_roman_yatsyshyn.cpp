#include <iostream>
#include <complex>

using namespace std;

complex<double> difference(complex<double> a1, complex<double> a2){
    return a1-a2;
}

double difference(double a1, double a2){
    return a1-a2;
}

int main(){
    double real1, img1, real2, img2, a_1, a_2;
    cout << "Real and imaginary part of first complex number: ";
    cin >> real1 >> img1;
    cout << "Real and imaginary part of second complex number: ";
    cin >> real2 >> img2;
    complex<double> a1(real1, img1);
    complex<double> a2(real2, img2);

    cout << "Two rational numbers: ";
    cin >> a_1 >> a_2;
    
    cout << difference(a1, a2) << "\n";
    cout << difference(a_1, a_2) << "\n";
}