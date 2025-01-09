#include <iostream>
#include <vector>

using namespace std;

bool check(vector<bool> &v)
{
    for (int i = 0; i < v.size(); i++)
        if (!v[i])
            return false;
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<bool> row_virus(n, false);
    vector<bool> col_virus(m, false);

    for (int i = 0; i < n; i++)
    {
        string row;
        getline(cin, row);

        for (int j = 0; j < m; j++)
            if (row[j] == '1')
            {
                row_virus[i] = true;
                col_virus[j] = true;
            }
    }

    bool all_rows = check(row_virus);
    bool all_cols = check(col_virus);

    if (all_rows || all_cols)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}