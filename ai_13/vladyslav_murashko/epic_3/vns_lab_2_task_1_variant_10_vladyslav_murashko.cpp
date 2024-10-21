#include <iostream>

unsigned long long factorial(int n)
{
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

double calculate_sum(double epsilon)
{
    int n = 0;
    double S = 0.0;

    while (true)
    {
        double an = (double)factorial(n) / factorial(2 * n);

        if (an < epsilon)
        {
            return S;
        }

        S += an;

        ++n;
    }
}

int main()
{
    double epsilon = 0.0001;
    double sum = calculate_sum(epsilon);

    std::cout << "The sum of the series: " << sum << std::endl;
    return 0;
}
