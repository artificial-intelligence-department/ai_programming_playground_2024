#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int CUBE = 3; // Цілочисельна константа використовується для піднесення до куба

    double a = 1.1; 
    double b = 0.004; 
    double x = 0.2; 

    double y = pow(sin(pow(a, 2)), CUBE) - pow(x / b, 1.0 / CUBE); //Використав математичні функції

    double z = (pow(x, 2) / a) + pow(cos(pow(x + b, CUBE)), 2);

    cout << "y = " << y << endl;
    cout << "z = " << z;

    return 0;
}