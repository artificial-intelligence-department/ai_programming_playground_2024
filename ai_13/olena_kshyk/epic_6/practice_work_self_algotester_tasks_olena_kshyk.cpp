#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void row_change(vector<int> &v, int a)
{
    for (int i = 1; (a - i) >= 0; i++)
        v[a - i] = i + v[a];

    for (int i = 1; (a + i) < v.size(); i++)
        v[a + i] = i + v[a];
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    cin >> x >> y;
    x--;
    y--;
    vector<vector<int>> res(n, vector<int>(m, -1));
    res[x][y] = 0;

    for (int i = 1; (x - i) >= 0; i++)
        res[x - i][y] = i;

    for (int i = 1; (x + i) < n; i++)
        res[x + i][y] = i;

    for (int i = 0; i < n; i++)
        row_change(res[i], y);

    int max = 0;
    for (auto row : res)
    {
        int row_max = *max_element(row.begin(), row.end());
        max = (row_max > max) ? row_max : max;
    }

    for (auto v : res)
    {
        for (auto x : v)
            cout << abs(x - max) << " ";
        cout << endl;
    }

    return 0;
}