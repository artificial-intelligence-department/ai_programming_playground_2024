#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;
int main()
{
    double hx = 0.21, ha = 0.1;
    double a_start = -0.1, a_end = -1.4;
    double x_start = 0.5, x_end = 3.1;
    double b = 1.5;

    
    cout << "a" << setw(20) << "x" << setw(18) << "y" << endl;
    cout << fixed << setprecision(4);
    for (double a = a_start; a >= a_end; a -= ha)
    {
        for (double x = x_start; x <= x_end; x += hx)
        {
            double y;
            if (x < b)
            {
                y = sin(fabs(a * x + pow(b, a)));
            }
            if (x >= b)
            {
                y = cos(fabs(a * x - pow(b, a)));
            }
            cout << setw(5) << a << setw(15) << x << setw(15) << y << endl;
        }
    }
    return 0;

}