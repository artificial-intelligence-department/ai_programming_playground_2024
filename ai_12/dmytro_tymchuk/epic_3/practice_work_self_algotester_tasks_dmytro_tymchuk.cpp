#include<iostream>
using namespace std;

int main()
{
    int m, n, arr[100][100];

    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>arr[i][j];
        }
    }
    
    int  min_max = 10000000, max_in_column;

    for (int j = 0; j < m; j++)
    {
        max_in_column = arr[0][j];
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] > max_in_column) max_in_column = arr[i][j];
        }
        
        if (max_in_column < min_max)
        {
            min_max = max_in_column;
        }
    }

    cout<<min_max<<endl;
    
    return 0;
}