#include <iostream>
using namespace std;

int main()
{
    int m, n, maxInCol;
    int column = 0, max = 1000000;
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        maxInCol = arr[0][i];
        for (int j = 0; j < n; j++)
        {
            if (arr[j][i] > maxInCol)
                maxInCol = arr[j][i];
        }

        if (maxInCol < max)
        {
            column = i;
            max = maxInCol;
        }
    }

    cout << max << endl;

    return 0;
}