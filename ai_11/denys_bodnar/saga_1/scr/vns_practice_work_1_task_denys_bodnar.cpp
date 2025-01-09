#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.7;
    double b = 0.05;
    double x = 0.5;

    double R = (pow(x, 3) * (x + 1)) / pow(b, 2) - pow(sin(x * (x + a)), 2); // рахує R

    double S = sqrt(x * b / a) + pow(cos(x + b), 2) * pow(x + b, 3); // рахує S

    cout << "R = " << R << endl; // виводимо R
    cout << "S = " << S << endl; // виводимо S

    return 0;
}