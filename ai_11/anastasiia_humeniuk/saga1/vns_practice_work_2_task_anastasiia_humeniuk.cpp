#include <iostream>
#include <cmath>

using namespace std;

const int a = 2; // Використано константу
const int b = 3; // Використано константу
const int c = 7; // Використано константу
const double hx = 0.31; // Використано константу
const double x_start = 0; // Використано константу
const double x_end = 5; // Використано константу

int main() {

    for (double x = x_start; x <= x_end; x += hx) { // Використано цикл for
        double y;

        if (x < 2) { // Використано умовний оператор if
            y = pow(a, b - x) + c; // Математична операція
        } else if (x >= 2 && x <= 4) { // Використано умовний оператор else if
            y = pow(b, c - x) + a; // Математична операція
        } else { 
            y = pow(c, a - x) + b; // Математична операція
        }

        cout << "x = " << x << ", y = " << y << endl; // Використано оператор виведення
    }

    return 0;
}
