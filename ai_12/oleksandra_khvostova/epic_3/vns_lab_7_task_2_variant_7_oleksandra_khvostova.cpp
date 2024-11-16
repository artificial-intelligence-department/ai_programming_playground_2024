#include <iostream>
using namespace std;

int division(int num1, int num2) {
    int res=num1/num2;
    cout<<"Result of integer division: "<<res;
    return res;
}

struct Complex {
    double real;
    double imag;
};

void print(const Complex& c) {
    cout << c.real;
    if (c.imag >= 0) cout << " + " << c.imag << "i";
    else cout << " - " << -c.imag << "i";
    cout << endl;
}

Complex division(const Complex& a, const Complex& b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    cout << "Result of complex division: ";
    print(result);
    return result;
}

int main() {
    Complex result = division({3,-2}, {7,1});
    int res =division(6, 2);

    return 0;
}