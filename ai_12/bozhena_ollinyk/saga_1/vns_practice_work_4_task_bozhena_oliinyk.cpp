#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double y, x[18];
    int n = 0;
    for (double i = -4; i <= 4; i += 0.5)
    {
        x[n] = i;
        n++;
    }

    for (int i = 0; i < n; i++)
    {
        y = fabs(x[i] - 2) + fabs(x[i] + 1);
        cout << "x = " << x[i] << "   " << '\t' << "y = " << y << endl;
    }
}