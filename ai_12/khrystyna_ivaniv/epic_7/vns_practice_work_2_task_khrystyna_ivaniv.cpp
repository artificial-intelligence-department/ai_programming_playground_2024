#include <math.h>
#include <iostream>
int main()
{
    double x, y;
    double sum = 0;
    std::cin >> x;
    for (int i = 1; i <= 10; i++)
    {
        y = (pow(x, i)) / i;
        sum +=y;
    }
    std::cout << sum;
     return 0;
}