#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x = 1.45;
    double y = -1.22;
    double z = 3.5;
    double pi = 3.14;

    double b = 1 + (pow(z, 2) / 3 + (pow(z, 2) / 5));
    double a = 2 * cos(x -(pi / 6)) * b / (0.5 + pow(sin(y), 2));
    
    cout << "a = " << a << '\t' << "b = " << b;

    return 0;
}