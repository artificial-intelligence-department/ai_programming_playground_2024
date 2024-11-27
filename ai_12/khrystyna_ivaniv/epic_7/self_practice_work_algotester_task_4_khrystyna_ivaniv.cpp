#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int trees = 0;
    for (int j = 0; j < m; j++)
    {
        int max_amount = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] > max_amount)
                max_amount = a[i][j];
        }
        trees += max_amount;
    }

    cout << trees;
    return 0;
}
