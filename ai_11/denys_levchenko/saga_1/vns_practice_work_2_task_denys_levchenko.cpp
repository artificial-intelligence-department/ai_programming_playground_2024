#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double hx = 0.2;     
    double ha = 0.3;      
    double x_start = 0.5; 
    double x_end = 3.1; 
    double a_start = 0.1;   
    double a = a_start; 

    // Формат виведення
    cout << fixed << setprecision(4);

    // Цикл for
    for (double x = x_start; x <= x_end; x += hx, a += ha) {
            double y; 
            if (x > 2) { // оператори та розгалуження
                y = cos(a * x + 2); 
            } else {
                y = tan(abs(x - 2 * a)); 
            }

            cout << "x = " << x << ", a = " << a << ", y = " << y << endl;
        }

    return 0;
}
