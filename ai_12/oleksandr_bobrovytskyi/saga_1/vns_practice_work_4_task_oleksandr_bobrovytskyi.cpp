#include<iostream>

using namespace std;

int main()
{
    double y;
    double step = 0.5;
    double x_min = -4.0, x_max = 4.0;

    cout << "x" << "\t" << "y" << endl;
    cout << "-----------" << endl;

    for(double x = x_min; x <= x_max; x += step)
    {
        y = 2*x*x - 5*x - 8;
        cout << x << "\t" << y << endl;
    }

    return 0;
}