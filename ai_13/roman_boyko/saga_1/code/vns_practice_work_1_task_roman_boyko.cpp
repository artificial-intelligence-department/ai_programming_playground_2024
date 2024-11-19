#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    float a = 5.0, b = 6.0, c = 7.0;
    float p = (a + b + c) / 2.0;
    float h1 = float(2 / a * (sqrt(p * (p - a) * (p - b) * (p - c))));
    float h2 = float(2 / b * (sqrt(p * (p - a) * (p - b) * (p - c))));
    float h3 = float(2 / c * (sqrt(p * (p - a) * (p - b) * (p - c))));
    cout << "h1: " << setprecision(4) << h1 << endl;
    cout << "h2: " << setprecision(4) << h2 << endl;
    cout << "h3: " << setprecision(4) << h3 << endl;
}
