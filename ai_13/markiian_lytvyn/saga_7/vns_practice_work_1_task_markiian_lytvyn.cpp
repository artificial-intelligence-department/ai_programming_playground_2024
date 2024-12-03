#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a = 3.2;
    double b = 17.5;
    double x = -4.8;
    double y = pow(b, 3) * pow(tan(x), 2) - a/pow(sin(x/a), 2);
    double z = a * exp(-sqrt(3)) * cos((b*x)/a);
    cout << "Y = " << y << endl;
    cout << "Z = " << z << endl;
    return 0;
}