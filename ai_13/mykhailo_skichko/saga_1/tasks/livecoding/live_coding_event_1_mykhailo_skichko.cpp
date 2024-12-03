#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>

const int myVariant = 78;

double function_1()
{
    double a, b;
    int c, d, e;
    double f;

    std::cin >> a >> b;
    std::cin >> c >> d >> e;
    std::cin >> f;

    std::vector<double> values = {a, b, (double)c, (double)d, (double)e, f};
    std::sort(values.begin(), values.end());

    double maxSum = 0, minSum = 0;

    for (int i = 0; i < 3; ++i)
    {
        minSum += values[i];
    }

    for (int i = 2; i < 5; ++i)
    {
        maxSum += values[i];
    }

    double x = 0;
    if (maxSum > minSum * 2)
    {
        x = maxSum * minSum;
    }
    else if (maxSum > minSum * 3)
    {
        x = maxSum / minSum;
    }
    else if (maxSum > minSum * 4)
    {
        x = maxSum + minSum;
    }

    x /= myVariant;
    std::cout << x << std::endl;

    return x;
}

double function_2(const double &x)
{
    int **matrix = new int *[5];
    for (int count = 0; count < 5; ++count)
    {
        matrix[count] = new int[5];
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            matrix[i][j] = x;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            matrix[i][j] = (matrix[i][j] + myVariant + i + j) * (rand() % 100) + 1;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int main()
{
    double x = function_1();
    function_2(x);

    return 0;
}
