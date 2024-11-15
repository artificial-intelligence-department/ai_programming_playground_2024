#include <iostream>
#include <random>
using namespace std;

int sumOfBelowNumbers(int matrix[5][5])
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += matrix[i][j];
        }
    }

    return sum;
}

int main()
{
    int matrices[10][5][5];
    int sums[10];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distr(-100, 100);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                matrices[i][j][k] = distr(gen);
            }
        }
        sums[i] = sumOfBelowNumbers(matrices[i]);
    }

    int max = sums[0];
    for (int i = 1; i < 10; i++)
    {
        if (sums[i] > max)
            max = sums[i];
    }
    cout << max;
    return 0;
}