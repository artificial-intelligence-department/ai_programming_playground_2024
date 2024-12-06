// Variant 12

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double x_s = 1, x_e = 10, hx = 2;
    double y_s = -4, y_e = 3, hy = 1;

    for (double y = y_s; y <= y_e; y += hy) 
    {
        for (double x = x_s; x <= x_e; x += hx) 
        {
            double z;
            if (x > y) 
            {
                z = (x * x) / pow((x - 5), 3);
            } 
            else 
            {
                z = ((x - 2) * (x - 2) * (x - 2)) / (y * pow((x - 5), 4));
            }

            cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
        }
    }

    return 0;
}
