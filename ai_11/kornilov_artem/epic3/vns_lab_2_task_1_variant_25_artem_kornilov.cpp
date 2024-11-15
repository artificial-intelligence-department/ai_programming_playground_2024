#include <iostream>
#include <cmath>

#define e 2.71828

using namespace std;

int main () {

    double sum = 0.0;

    for (double n = 1.0; n < 8; n++) {

        double br = (-1) * sqrt(n); 

        double a_n = (pow(n, 2) * pow(e, br));

        sum += a_n; 
        
        cout << n << ") " << a_n << endl << sum << endl; 
    }

    return 0;
}