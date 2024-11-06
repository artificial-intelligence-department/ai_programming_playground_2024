#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x = 0.1;
    double step = (1 - 0.1) / 10;
    double e = 0.0001;
    double sum = 1;
    double sumEpsilon = 1;
    double fact = 1;
    double n = 1.0;
    for (int i = 1; i < 20; i++)
    {
        n = 1.0;
        sum = 1;
        sumEpsilon = 1;
        x += step;
        fact = 1.0;

        for (double j = 1; j <= 20; j++)
        {
            fact *= j;
            sum += pow((2.0 * x), j) / fact;
        }
        fact = 1.0;
        while (true)
        {
            fact *= n;
            sumEpsilon += pow((2.0 * x), n) / fact;

            if (pow((2.0 * x), n) / fact < e)
            {
                break;
            }
            n++;
        }

        cout << "X= " << x << " SN= " << sum << " SE= " << sumEpsilon << " Y= " << exp(2 * x) << endl;
    }
    return 0;
}