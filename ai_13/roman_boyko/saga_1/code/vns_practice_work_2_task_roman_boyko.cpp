#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double h = 0.1;
    double x = 0.3;
    int counter = 0;
    while (x < 5)
    {
        double res = cos(x * x) * exp(-x);
        if (res < 0)
        {
            counter++;
        }
        x += h;
    }
    cout << "counter: " << counter << endl;
}
