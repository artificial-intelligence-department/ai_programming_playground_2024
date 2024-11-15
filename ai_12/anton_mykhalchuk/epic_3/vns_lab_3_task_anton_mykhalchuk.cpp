#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double eps = 0.0001;
    double exactValueY, xn, sn, xe, se;
    int i;

    for (double k = 0.1; k <= 0.8 + eps; k += 0.07)
    {
        exactValueY = 0.25 * log(((1 + k) / (1 - k))) + 0.5 * atan(1 / k);
        sn = 0;
        for (int n = 0; n <= 3; n++)
        {
            xn = pow(k, (4 * n + 1)) / (4 * n + 1);
            sn += xn;
        }
        xe = k;
        se = 0;
        i = -1;
        while (xe >= eps)
        {
            i++;
            xe = pow(k, (4 * i + 1)) / (4 * i + 1);
            se += xe;
        }

        cout << "X = " << k << " SN = " << sn << " SE = " << se << " Y = " << exactValueY << endl;
    }

    return 0;
}