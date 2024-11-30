#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double y;
    double x = 0.5;
    const double hx = 0.2;
    const double ha = 0.3;
    double a = 0.1;
    const double x_max = 3.1;

    while (x <= x_max)
    {
        if (x <= 2)
        {
            y = tan(abs(x - 2*a));
        }
        else
        {
            y = cos(a*x + 2);
        }

        cout << "X = " << x << "; a = " << a << "; Y = " << y << endl;
        x += hx;
        a += ha;
    }
}



