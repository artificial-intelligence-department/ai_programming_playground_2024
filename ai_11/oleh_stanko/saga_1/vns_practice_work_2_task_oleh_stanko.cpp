//var 18
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double h_x = 0.5;
    double x = -2.5;
    double z;
    double y;
    while (x < 2.1) // for x=2
    {
        z = fabs(x) + pow(x, 2);
        y = z*(sin (pow (2 + x, 2)) / (2+x));
        cout << "x = " << x << "\t z = " << z << "\t y = " << y << endl;
        x+=h_x;
    }
    return 0;     

}