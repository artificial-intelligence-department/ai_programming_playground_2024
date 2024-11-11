#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int x, y;
    cin >> x >> y;
    int matrix[N][M];
    int maxNum = 0;
    if (N / x >= 2)
    {
        maxNum += N - x;
    }
    else
    {
        maxNum += x - 1;
    }
    if (M / y >= 2)
    {
        maxNum += M - y;
    }
    else
    {
        maxNum += y - 1;
    }
    x -= 1;
    y -= 1;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            if (x > i)
            {
                matrix[i][j] = maxNum - x + i;
            }
            else
            {
                matrix[i][j] = maxNum - i + x;
            }
            if (y > j)
            {
                matrix[i][j] -= y - j;
            }
            else
            {
                matrix[i][j] -= j - y;
            }
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}