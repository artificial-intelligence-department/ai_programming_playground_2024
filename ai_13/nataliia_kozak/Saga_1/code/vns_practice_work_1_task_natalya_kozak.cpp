#include <iostream>
#include <cmath>
using namespace std;
int main(){
    float a = 0.3, b = 0.9, x = 0.53;
    float R = sqrt(x*x+b) - b*b*pow(sin(x+a), 3)/x;
    float Y;
    Y = (pow(a, 2*x) + pow(b, -x)*cos(a+b)*x)/abs(x+1);
    cout << endl << Y;
    return 0;
}