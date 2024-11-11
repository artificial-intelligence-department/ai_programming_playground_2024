#include <iostream>
#include <vector>
using namespace std;

bool isRowHasNegative(int *row, int count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (row[i] < 0)
            return true;
    }
    return false;
}

void printTheMatrix(int **matrix, int N)
{
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    const int N = 5;
    int **matrix = new int *[N];
    for (size_t i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
        for (size_t j = 0; j < N; j++)
        {
            matrix[i][j] = (rand() - RAND_MAX / 10) % 100;
        }
    }

    cout << "\nInitial matrix: \n\n";
    printTheMatrix(matrix, N);

    for (int i = N-1; i >= 0; i--)
    {
        if (isRowHasNegative(matrix[i], N))
        {
            for (size_t j = i; j < N - 1; j++)
            {
                matrix[j] = matrix[j + 1];
            }
            matrix[N - 1] = new int[N];
            for (size_t j = 0; j < N; j++)
            {
                matrix[N - 1][j] = 0;
            }
            
        }
    }

    cout << "\nMatrix after deleting rows with negative numbers:\n\n";
    printTheMatrix(matrix, N);

    for (size_t i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}