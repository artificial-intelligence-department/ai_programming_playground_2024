#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int f = 1;
    double s = 0;
    for (int n = 1; n < 11; n++)
    {
        f *= n;
        double an = (f) / pow(n, sqrt(n));
        s += an;
    }
    cout << "Sum of series = " << s;
    return 0;
}