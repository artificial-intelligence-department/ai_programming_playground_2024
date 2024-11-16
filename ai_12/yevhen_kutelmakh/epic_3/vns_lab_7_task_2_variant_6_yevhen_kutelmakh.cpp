#include <iostream>
using namespace std;

struct Imaginary {
    int Re;
    int Im;
};

double substract(double a, double b) {
    return a - b;
}

Imaginary substract(Imaginary &num1, Imaginary &num2) {
    Imaginary res;
    res.Re = num1.Re - num2.Re;
    res.Im = num1.Im - num2.Im;
    return res;
}

int main() {
    double a, b;
    cout << "Enter real numbers for substraction: ";
    cin >> a >> b;
    cout << "Substraction of real numbers a and b = " << substract(a, b) << "\n";
    Imaginary x, y;
    cout << "Enter real parts of complex numbers for substraction: ";
    cin >> x.Re >> y.Re;
    cout << "Enter imaginary parts of complex numbers for substraction: ";
    cin >> x.Im >> y.Im;
    Imaginary res = substract(x, y);
    cout << "Substraction of complex numbers x and y = " << res.Re << " + " << res.Im << "i";
    return 0;
}