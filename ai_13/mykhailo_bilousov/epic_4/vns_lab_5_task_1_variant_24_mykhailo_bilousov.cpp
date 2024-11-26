#include <iostream>

#define N 10

int count_biggers(int** a)
{
    int min_on_diag = a[0][0];
    int count = 0;
    for (size_t i = 1; i < N; i++)
    {
        if (a[i][i] < min_on_diag) min_on_diag = a[i][i];
    }
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            if (a[i][j] > min_on_diag) count++;
        }
    }
    return count;
}

int main()
{
    srand(time(0));
    int** arr = new int*[N];
    for (size_t i = 0; i < N; i++) arr[i] = new int[N];
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < N; j++)
            arr[i][j] = rand() % 0x10000;

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
            std::cout << ((i == j) ? "*" : "") << arr[i][j] << ((i == j) ? "*" : "") << "\t";
        std::cout << std::endl;
    }

    std::cout << count_biggers(arr) << std::endl;
    return 0;
}