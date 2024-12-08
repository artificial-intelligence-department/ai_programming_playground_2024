#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double p, a, b, x = 1.25, y = 0.93, e = 2.72;
    double a1, a2, a3, b1, b2;
    a1 = ((x+y)*(x+y)) / ((x+4)*(x+4)*(x+4));
    a2 = pow(e, -(x-2)) + (x*x*x +4);
    a3 = 1 - y;
    a = (a3*a1) / a2;

    b1 = 1 + cos(y-2);
    b2 = x*x + pow(sin(y-2), 2);
    b = b1 / b2;

    p = a / b;

    cout << p;

    return 0;
}
