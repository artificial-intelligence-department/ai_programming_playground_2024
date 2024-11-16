#include <iostream>
using namespace std;

struct Imaginary 
{
    int Re;  
    int Im;  
};

double subtract(double a, double b) {
    return a - b;
}

Imaginary subtract(Imaginary &num1, Imaginary &num2) 
{
    Imaginary res;
    res.Re = num1.Re - num2.Re;
    res.Im = num1.Im - num2.Im;
    return res;
}

int main() 
{
    double num1, num2;
    cout << "Enter two real numbers for subtraction: ";
    cin >> num1 >> num2;
    cout << "Result of subtraction = " << subtract(num1, num2) << "\n";

    Imaginary complex1, complex2;
    cout << "Enter the real part of the first complex number: ";
    cin >> complex1.Re;
    cout << "Enter the imaginary part of the first complex number: ";
    cin >> complex1.Im;

    cout << "Enter the real part of the second complex number: ";
    cin >> complex2.Re;
    cout << "Enter the imaginary part of the second complex number: ";
    cin >> complex2.Im;

    Imaginary result = subtract(complex1, complex2);
    cout << "Result of complex number subtraction = " << result.Re << " + " << result.Im << "i\n";
    
    return 0;
}
