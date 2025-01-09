#include <iostream>
#include <cmath>

using namespace std;
//використав дійсну змінну, цикл вайл, математичні операції,
//вивід, умовні оператори та розгалуження
int main () {
    float h_a = 0.5, h_x = 0.2, a = 1.0, x = 0.0, b = 1.2;
    while (x < 1.1 || a < 2.0){
        double y = (4*a*pow(x, 2) + 37*x + b)/(a - 0.5); 
        cout << "y = (4a * x^2 + 37x + b)/(a - 0.5) = " << y 
        << " at a = " << a << ", x = " << x << ", b = " << b << endl;
        if (a < 2.0){
            a += h_a;
        }
        x += h_x;
    }
    return 0;
}