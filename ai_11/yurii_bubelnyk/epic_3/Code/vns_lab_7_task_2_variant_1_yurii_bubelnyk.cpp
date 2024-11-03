#include <iostream>
#include <complex>
using namespace std;

//а) для додавання цілих чисел;
//б) для додавання комплексних чисел.

int Sum(int a, int b);
complex<double> Sum(const complex<double>& num1, const complex<double>& num2);

int main(){

    int a,b;
    cout << "Enter first number: " << endl;
    cin >> a;
    cout << "Enter second number: " << endl;
    cin >> b;

    int real1, imag1, real2, imag2;
    cout << "Enter real and imaginary part of the first complex number: ";
    cin >> real1 >> imag1;
    cout << "Enter real and imaginary part of the second complex number: ";
    cin >> real2 >> imag2;

    complex<double> num1(real1, imag1);
    complex<double> num2(real2, imag2);

    cout << Sum(a,b) << endl;
    cout << Sum(num1,num2) << endl;

    return 0;
}

int Sum(int a, int b){
    int result = a + b;
    return result;
}

complex<double> Sum(const complex<double>& num1, const complex<double>& num2) {
    complex<double> result = num1 + num2;
    return result;
}
