#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double z, x = 1.0, y = -4.0;
    double stepX = 2, stepY = 1;

    for (double x = 1.0; x <= 10; x += stepX)
    {
        for (double y = -4.0; y <= 3; y += stepY)
        {
            z = 0;
            if (x > y)
            {
                z = pow(x, 2) / (pow((x - 5), 3));
            }
            else
            {
                z = pow((x - 2), 3) / y * pow((x - 5), 4);
            }
            cout << "z = " << z << endl;
        }
    }

    return 0;
}