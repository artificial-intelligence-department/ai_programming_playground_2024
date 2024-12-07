#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double a = -0.5;
    double b = 1.7;
    double t = 0.44;

    double y = exp(-b * t) * sin(a * t + b) - sqrt(fabs(b * t + a));
    double s = b * sin(pow(a * t, 2) * cos(2 * t)) - 1;

    cout << "y = " << y << endl;
    cout << "s = " << s << endl;

    return 0;
}
