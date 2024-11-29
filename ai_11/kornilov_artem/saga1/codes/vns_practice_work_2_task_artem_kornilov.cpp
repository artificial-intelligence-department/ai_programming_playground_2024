#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double x = -2.5;
    int xMax = 2;
    double step = 0.5;
    double y, z;


    cout << fixed << setprecision(4);
    cout << "x" << "\t\t" << "z" << "\t\t" << "y\n";
    cout << "----------------------------------------\n" ;
    
    for (double i = x; i <= xMax; i+=step) {
        z = abs(i) + pow (i, 2);
        y = z*sin(pow(i + 2, 2))/(i + 2);
        
        if (i + 2 == 0) {
            cout << i << "\t\t" << z << "\t\t" << "------" << "\n";
        }
        
        else {
        cout << i << "\t\t" << z << "\t\t" << y << "\n";
        }
    }

    return 0;
}