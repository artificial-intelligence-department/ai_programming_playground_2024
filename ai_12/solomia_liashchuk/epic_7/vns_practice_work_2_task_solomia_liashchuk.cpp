#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a = 2, b = 3, c = 7;
    double hx = 0.31;
    double x_start = 0, x_end = 5;

    cout << setw(10) << "x" << setw(15) << "y" << endl;
    cout << "-----------------------------" << endl;

    for (double x = x_start; x <= x_end; x += hx)
    {
        double y;
        if(x < 2) 
        {
            y = pow(a, b - x) + c;
        }else if(x >= 2 && x <= 4) 
        {
            y = pow(b, c - x) + a;
        }else if(x > 4)
        {
            y = pow(c, a - x) + b;
        }
              
   
    cout << setw(10) << fixed << setprecision(2) << x 
       << setw(15) << fixed << setprecision(2) << y << endl; 

    }

    return 0;
}

