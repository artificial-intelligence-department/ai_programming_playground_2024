#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <climits>

const int myVariant = 78;

double partition(double array[], int lb, int ub)
{
    double pivot = array[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    int temp = array[end];
    array[end] = array[lb];
    array[lb] = temp;
    return end;
}

void quick_sort(double array[], double lb, double ub)
{
    while (lb < ub)
    {
        int loc = partition(array, lb, ub);
        quick_sort(array, loc + 1, ub);
        quick_sort(array, lb, loc - 1);
    }
}

int getMinValue(int array[], int size)
{
    int minValue = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
    }
    return minValue;
}

double getMinValue(double *array, int size)
{
    double minValue = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < minValue)
        {
            minValue = array[i];
        }
    }
    return minValue;
}

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

double **function_2(const double &x)
{
    double **matrix = new double *[5];
    for (int count = 0; count < 5; ++count)
    {
        matrix[count] = new double[5];
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

    return matrix;
}

double *function_3(double **tower)
{
    double *resultantArray = new double[5];

    double *minValues_v1 = new double[5];
    double *minValues_v2 = new double[5];

    for (int i = 0; i < 5; ++i)
    {
        minValues_v1[i] = getMinValue(tower[i], 5);
    }

    for (int i = 0; i < 5; ++i)
    {
        quick_sort(tower[i], 0, 5);
        minValues_v2[i] = tower[i][0];
    }

    int ind = 0;
    while (minValues_v1[ind] == minValues_v2[ind])
    {
        ++ind;
        if (ind == 5)
        {
            break;
        }
    }
    if (ind == 5)
    {
        std::cout << "results match" << std::endl;
    }
    else
    {
        std::cout << "results don't match" << std::endl;
    }

    for (int i = 0; i < 5; ++i)
    {
        resultantArray[i] = minValues_v1[i];
    }

    return resultantArray;
}

double function_4()
{

    return 0.0;
}

double function_5()
{

    return 0.0;
}

double function_6()
{

    return 0.0;
}

int main()
{
    double x = function_1();
    double **tower = function_2(x);
    double *minValues = function_3(tower);

    return 0;
}
