#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> data(n, vector<int>(m));
    vector<int> maxCount(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> data[i][j];
            maxCount[j] = max(maxCount[j], data[i][j]);
        }
    }

    int trees = 0;
    for (int j = 0; j < m; j++)
    {
        trees += maxCount[j];
    }

    cout << trees << endl;
    return 0;
}