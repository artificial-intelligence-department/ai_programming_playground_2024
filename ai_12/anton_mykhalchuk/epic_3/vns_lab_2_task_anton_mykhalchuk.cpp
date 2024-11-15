#include <iostream>
using namespace std;

int main()
{
    const double eps = 0.0001;
    double an = 1, s = 0, d, n = -1;

    while (an >= eps)
    {
        n++;
        d = 10 / (n + 1);
        an *= d;
        s += an;
    }

    cout << "The sum of the series with an accuracy of epsilon = " << eps << " is " << s << " The value is reached at an = " << an << " when n = " << n;
    return 0;
}