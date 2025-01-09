#include <iostream>
#include <cstdlib> //for random
#include <algorithm>

const int VAR = 39;
float function_1();
float** fucntion_2(float &x);

int main()
{
    float x = function_1();
    std::cout << std::endl;
    float** tower = fucntion_2(x);
    return 0;
}

float function_1()
{
    float a, b;
    std::cin >> a >> b;
    int c, d, e;
    std::cin >> c >> d >> e;
    double f;
    std::cin >> f;
    double arr[6] = {double(a), double(b), double(c), double(d), double(e), f};
    double min_values[3];
    double max_values[3];
    for (int i = 0; i < 6; i++) //buble sort
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                double temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    double sum_max = 0;
    double sum_min = 0;
    double x = 0;
    for(int i = 0; i < 3; i++)
    {
        min_values[i] = arr[i];
        sum_min += arr[i];
    }
    for(int i = 0; i < 3; i++)
    {
        max_values[i] = arr[i + 3];
        sum_max += arr[i + 3];
    }
    if (sum_max > sum_min*2)
        x = sum_max * sum_min;
    else if (sum_max > sum_min*3)
        x = sum_max / sum_min;
    else if (sum_max > sum_min*4)
        x = sum_max + sum_min;

    x /= double(VAR);
    x = float(x);
    std::cout << x;

    return x;

}

float** fucntion_2(float &x)
{
    int SIZE = 5;
    float** matr = new float*[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        matr[i] = new float[SIZE];
        for(int j = 0; j < SIZE; j++)
        {
            matr[i][j] = x;
        }
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matr[i][j] = (matr[i][j] + float(VAR) + float(j) - float(i)) * float(rand() % 101);
    
    //printing
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << std::endl;
        }    
    return matr;
}

void fucntion_3(float** tower)
{
    int SIZE = 5;
    float arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            
        }
    }
}