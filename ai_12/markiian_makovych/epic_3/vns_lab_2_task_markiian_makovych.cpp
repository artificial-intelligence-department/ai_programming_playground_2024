#include <iostream>
using namespace std;
int main()
{

    double e = 0.00001;
    double x = 1;
    double sum = 0.0;
    double i = 2;
    while (true)
    {
        x = i / ((i - 1) * (i - 1));
        sum += x;
        if (x < e)
            break;

        i++;
    }
    cout << sum;
    return 0;
}
