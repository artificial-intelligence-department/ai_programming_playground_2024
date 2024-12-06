#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a = 16.5;
    double b = 3.4;
    double x = 0.61;
    double c = (b*x*x)/(exp(a*x) - 1.0);
    double s = (x*x*x*pow(tan((x+b)*(x+b)), 2) + a)*c  / sqrt(x+b);
    cout << "S = " << s;
    return 0;
}