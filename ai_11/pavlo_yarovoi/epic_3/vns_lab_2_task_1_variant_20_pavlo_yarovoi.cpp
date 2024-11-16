#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const double epsilon = 0.0001;
    double sum = 0.0;             
    double elementN;                  
    int n = 0;                    

    do {
        elementN = exp(n) * pow(100, -(n * n));
        sum += elementN;
        n++;         
    } while (elementN > epsilon);

    cout << "\n Sum of n elements:" << sum << endl;
    return 0;
}
