#include <iostream>
#include <iomanip>
#include <cmath> 

using namespace std;

int main (){

    double a = 1, b = 2; // fixed value
    double hx = 0.1, hy = 0.2; // steps

    double x_min = 1.0, x_max = 2.0;
    double y_min = 1.0, y_max = 2.0;
    double z; // for result

    cout << fixed << setprecision(4);

    for (double x = 1.0; x < x_max; x += hx){
        for (double y = 1.0; y < y_max; y += hy){
            if ( (x + y) <= 1){
                z = pow (x, a) + pow (y, b);
                cout << "x: " << x << " y: " << y << " z: " << z << endl;
            }
            else {
                z = a * pow (2, x) + log(b * x * y);
                cout << " x: " << x << " y: " << y << " z: " << z << endl;
            }
        }
    }

    return 0;
}