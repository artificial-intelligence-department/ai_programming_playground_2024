#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    
    double m = 2.1, t = 1.02, c = -1;

    double P = cbrt(m * tan(t) + fabs(c * sin (t) ));
    double K = pow(2, cos (t)) - m / (cbrt(fabsf(pow(2, m) - pow(2, t))));

    cout << "Result for P: " << P << endl;
    cout << "Result for K: " << K << endl;
    
    return 0;
}



