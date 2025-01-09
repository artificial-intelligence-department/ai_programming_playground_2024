#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a = 5.0, b = 6.0, c = 7.0;
    
    double p = (a + b + c) / 2;

    double ha = (2 / a) * sqrt(p * (p - a) * (p - b) * (p - c));
    double hb = (2 / b) * sqrt(p * (p - a) * (p - b) * (p - c));
    double hc = (2 / c) * sqrt(p * (p - a) * (p - b) * (p - c));

    cout << "Висота до сторони a: " << ha << endl;
    cout << "Висота до сторони b: " << hb << endl;
    cout << "Висота до сторони c: " << hc << endl;

    return 0;
}
