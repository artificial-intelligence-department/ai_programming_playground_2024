#include <iostream>

using namespace std;

int main()
{
    int matrix[5][5] = {{1, 2, 3, 4, 5},
                        {6, 7, 23, 1, 4},
                        {2, 5, 53, 2, 1},
                        {1, 2, 3, 5, 6},
                        {6, 43, 85, 2, 6}};
    int maxColumns[5] = {};
    int minColumns[5] = {};
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        max = 0;
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] > max)
            {
                max = matrix[i][j];
            }
        }
        maxColumns[i] = max;
    }
    for (int i = 0; i < 5; i++)
    {
        int min = 999999;
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] <= min)
            {
                min = matrix[i][j];
            }
        }
        minColumns[i] = min;
    }
    cout << "MAX" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << maxColumns[i] << " ";
    }
    cout << endl;
    cout << "MIN" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << minColumns[i] << " ";
    }
    cout << endl;
    cout << "MATRIX" << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 4; j >= 0; j--)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "TRANSPOSED MATRIX" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                cout << matrix[i][j] << " ";
            }
            else
            {
                cout << matrix[j][i] << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "TURNED MATRIX" << endl;
    for (int i = 4; i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}