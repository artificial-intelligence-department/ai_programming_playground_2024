#include <iostream>
using namespace std;


int multiply(int a, int b)
{
    return a * b;
}


struct Complex
{
    int real;
    int imag;
};

Complex multiply(Complex c1, Complex c2) 
{
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}


void printComplex(Complex c) {
    cout << c.real << " + " << c.imag << "i" << endl;
}

int main() {

    int a, b;
    cout << "Enter first number :";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    cout << "multiplication of full number  : " << multiply(a, b) << endl;



    Complex c1, c2;
    cout << "Enter full and imaginary part of complex number for second number : ";
    cin >> c1.real >> c1.imag;
    cout << "Enter full and imaginary part of complex number for first number : ";
    cin >> c2.real >> c2.imag;


    Complex result = multiply(c1, c2);
    cout << "multiplication  of complex number: ";
    printComplex(result);



    return 0;
}






