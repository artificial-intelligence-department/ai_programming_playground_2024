#include<bits/stdc++.h>

using namespace std;

const int n = 5; 

struct matrix
{
    int arr[n][n];
};

void printMatrix(matrix m)
{
    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {
            cout << m.arr[i][j];
        }
        cout << endl;
    }
}

bool CheckSymetry(matrix m)
{
    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {   
            if(m.arr[i][j] != m.arr[j][i])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    matrix m;

    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {
            m.arr[i][j] = n + i - j;
        }
    }

    printMatrix(m);
    cout << endl;

    int ArrColumnMin[n];

    for (int i = 0; i < n ; i++)
    {
        int min = INT_MAX;
        for(int j = 0;j < n; j++)
        {   
            if(m.arr[j][i] < min)
            {
                min = m.arr[j][i];
            }
        }
        ArrColumnMin[i] = min;
    }

    for (int i = 0; i < n ; i++)
    {
        cout << ArrColumnMin[i] << " ";
    }
    cout << endl;

    int ArrColumnMax[n];

    for (int i = 0; i < n ; i++)
    {
        int max = INT_MIN;
        for(int j = 0;j < n; j++)
        {   
            if(m.arr[j][i] > max)
            {
                max = m.arr[j][i];
            }
        }
        ArrColumnMax[i] = max;
    }

    for (int i = 0; i < n ; i++)
    {
        cout << ArrColumnMax[i] << " ";
    }
    cout << endl;

    int ArrRowMin[n];

    for (int i = 0; i < n ; i++)
    {
        int min = INT_MAX;
        for(int j = 0;j < n; j++)
        {   
            if(m.arr[i][j] < min)
            {
                min = m.arr[i][j];
            }
        }
        ArrRowMin[i] = min;
    }

    for (int i = 0; i < n ; i++)
    {
        cout << ArrRowMin[i] << " ";
    }
    cout << endl;

    int ArrRowMax[n];

    for (int i = 0; i < n ; i++)
    {
        int max = INT_MIN;
        for(int j = 0;j < n; j++)
        {   
            if(m.arr[i][j] > max)
            {
                max = m.arr[i][j];
            }
        }
        ArrRowMax[i] = max;
    }

    for (int i = 0; i < n ; i++)
    {
        cout << ArrRowMax[i] << " ";
    }
    cout << endl << endl;

    for (int i = n-1; i >= 0 ; i--)
    {
        for(int j = n - 1;j >= 0; j--)
        {   
            cout << m.arr[j][i];
        }
        cout << endl;
    }

    int temp1;
    for(int i = 0;i < n; i++)
    {
        for(int j = i;j < n; j++)
        {   
            temp1 = m.arr[j][i];
            m.arr[j][i] = m.arr[i][j];
            m.arr[i][j] = temp1;
        }
    }

    cout << endl;
    printMatrix(m);

    matrix rotated90;
    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {   
            rotated90.arr[j][i] = m.arr[n - 1 - i][j]; 
        }
    }

    for(int i = 0;i < n; i++)
    {
        for(int j = 0;j < n; j++)
        {   
            m.arr[i][j] = rotated90.arr[i][j];
        }
    }

    cout << endl;
    printMatrix(m);

    if(CheckSymetry(m))
    {
        cout << "Matrix is symmetric";
    }
    else
    {
        cout << "Matrix is not symmetric";
    }

    return 0;
}