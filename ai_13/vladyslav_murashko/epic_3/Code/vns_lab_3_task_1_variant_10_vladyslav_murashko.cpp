#include <iostream>
#include <cmath>

namespace functions
{
    unsigned long long factorial(int n)
    {
        if (n >= 2)
        {
            return n * factorial(n - 1);
        }
        return 1;
    }

    double calculate_sum(double epsilon_or_n, bool is_epsilon_used_istead_of_n)
    {
        const int k = 10;
        const float a = 0.1, b = 1;
        double S = 0.0;
        float x = a;
        const float step = (b - a) / k;

        if (is_epsilon_used_istead_of_n)
        {
            double currentElement;
            int i;
            while (x <= b)
            {
                i = 0;
                while (true)
                {
                    currentElement = cos(i * x) / factorial(i);
                    if ((currentElement < epsilon_or_n && currentElement >= 0) || (currentElement > epsilon_or_n && currentElement < 0))
                    {
                        break;
                    }
                    S += currentElement;
                    i++;
                }
                x += step;
            }
            return S;
        }

        while (x <= b)
        {
            for (size_t i = 0; i <= epsilon_or_n; i++)
            {
                S += cos(i * x) / factorial(i);
            }
            x += step;
        }
        return S;
    }
}

int main()
{
    int n = 20;
    double epsilon = 0.0001;
    double sum_n = functions::calculate_sum(n, false);
    double sum_epsilon = functions::calculate_sum(epsilon, true);

    std::cout << "The sum of the series with n: " << sum_n << std::endl;
    std::cout << "The sum of the series with epsilon: " << sum_epsilon << std::endl;
    return 0;
}
