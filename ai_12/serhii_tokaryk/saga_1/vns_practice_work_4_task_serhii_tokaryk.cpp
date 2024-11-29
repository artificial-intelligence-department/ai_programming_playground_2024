#include <iostream>
#include <iomanip> 
#include <cmath>  
using namespace std;

int main() {
    
    double start = -4.0, end = 4.0;
    double step = 0.5; 

    cout << setw(10) << "x" << setw(10) << "y = |x|" << endl;
    cout << "--------------------" << endl;

    for (double x = start; x <= end; x += step) {
        double y = abs(x); 
        cout << setw(10) << fixed << setprecision(1) << x << setw(10) << fixed << setprecision(1) << y << endl;
    }

    return 0;
}
