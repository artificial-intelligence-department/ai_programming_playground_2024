#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double x = 0.25 , y = 0.79 , z = 0.81 , chisl , znam  , P  , Q ;
  
    chisl = 1 + pow(sin(x + 1), 2); 
    znam = 2 + fabs(x - (2 * pow(x, 3)) / (1 + pow(x, 2) * pow(y, 3))); 
    P = ( chisl / znam )+ pow(x, 4);
    Q = pow(cos(atan(1 / z)), 2);

    cout << "P = " << P << endl;
    cout << "Q = " << Q ;

    return 0;
}
