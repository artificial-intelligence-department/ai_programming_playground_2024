#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, l, r, c = 0;

    cin >> n >> m;

    vector<int> v1(n, 0);

    if (m < 1 || m > 1e5 || n < 1 || n > 1e5)
    {
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r >> c;

        if (l < 1 || r > n || r < l || c < 1 || c > 1e5)
        {
            return 1;
        }

        fill(v1.begin() + l - 1, v1.begin() + r , c);
    }

    for (int x = 0; x < n; x++)
    {
        cout << v1[x] << " ";
    }

    return 0;
}