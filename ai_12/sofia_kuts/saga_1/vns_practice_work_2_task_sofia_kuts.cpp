#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

int main() {
    double b = 2.0;       
    double h_x = 0.1;     
    double x_start = 1.0;  
    double x_end = 3.0;    
    double a_start = 1.0;  
    double a_end = 5.0;    

    cout << fixed << setprecision(4); 
    for (double a = a_start; a <= a_end; a += 1.0) {
        cout << "a = " << a << ":" << endl;

        for (double x = x_start; x <= x_end; x += h_x) {
            double y; 
            
            if (x < b) {
                y = sin(abs(a * x + pow(b, a))); 
            } else {
                y = cos(abs(a * x - pow(b, a))); 
            }

            cout << "x = " << x << ", y = " << y << endl;
        }
        cout << endl;
    }

    return 0;
}
