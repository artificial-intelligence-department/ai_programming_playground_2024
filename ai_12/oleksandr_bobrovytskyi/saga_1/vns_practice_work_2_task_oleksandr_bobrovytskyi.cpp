#include<bits/stdc++.h>

using namespace std;

int main()
{
    double hx = 0.1;
    double hy = 0.2;
    int a = 1;
    int b = 2;
    double z;

    for(double x = 1.0; x < 2.0; x += hx)
    {
        for(double y = 1.0; y < 2.0; y += hy)
        {
            if (x + y <= 1)
            {
                z = pow(a, x) + pow(b, y);
            }
            else if (x + y > 1)
            {
                z = a*x*x + log(b * x * y);
            }

            cout << z << endl;
        }
    }

    return 0;
}