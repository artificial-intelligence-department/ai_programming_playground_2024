#include <iostream>
#include <vector>
#include <algorithm> // для max_element і min_element
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lot(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lot[i][j];
        }
    }

    vector<int> max_el(m); // вектор для збереження максимумів кожного стовпця
    for (int i = 0; i < m; i++)
    {
        int col_max = lot[0][i];
        for (int j = 1; j < n; j++)
        {
            col_max = (col_max > lot[j][i]) ? col_max : lot[j][i];
        }
        max_el[i] = col_max;
    }

    // Знаходимо мінімальне значення серед максимумів стовпців
    int min_col = *min_element(max_el.begin(), max_el.end());
    cout << min_col;

    return 0;
}
