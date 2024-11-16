#include <iostream>

using namespace std;

const int N = 4;

bool matrix(int arr[])
{
    bool pos = false;
    int matrix[N][N] = {};
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = arr[count];
            count++;
        }
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (matrix[i + 1][0] > matrix[i][0])
        {
            pos = true;
        }
        else
        {
            pos = false;
            return pos;
        }
    }

    return pos;
}

int main()
{

    int arr[N * N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    if (matrix(arr) == 1)
    {
        cout << "It is possible" << endl;
    }
    else
    {
        cout << "It is impossible" << endl;
    }

    return 0;
}