#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = -0.5;
    double b = 1.7;
    double t = 0.44;

    double y1 = exp(-b*t)*sin(a*t + b);
    double y2 = sqrt(abs(b*t + a));
    double y = y1 - y2;

    double x = a*t*t*cos(2*t);
    double s = b*sin(x) - 1;

    cout << y << endl;
    cout << s << endl;

    return 0;
}