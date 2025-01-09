#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long a, b, c, r;
    cin >> a >> b >> c >> r;
    double p = static_cast<double>(a + b + c) / 2;
    double S = sqrt(p * (p - static_cast<double>(a)) * (p - static_cast<double>(b)) * (p - static_cast<double>(c)));
    if (r >= (a * b * c) / (4 * S))
    {
        cout << "+";
    }
    else
    {
        cout << "-";
    }
    if ((S / p) >= r)
    {
        cout << "+";
    }
    else
    {
        cout << "-";
    }
}