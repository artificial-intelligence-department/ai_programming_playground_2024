#include <iostream>
#include <cmath>

double calculateSum(double e)
{
    int n = 1;
    double sum_series = 0.0;
    double An;

    while (true)
    {
        double factorial_n = 1;
        for (int i = 1; i <= n; ++i)
        {
            factorial_n *= i;
        }

        An = (pow(factorial_n, 2)) / pow(2, n * n);

        if (An < e)
        {
            break;
        }

        sum_series += An;
        n++;
    }

    return sum_series;
}

int main()
{
    double e = 0.0001;
    double sum = calculateSum(e);

    std::cout << "sum of set with accuracy e = " << e << ": " << sum << std::endl;

    return 0;
}
