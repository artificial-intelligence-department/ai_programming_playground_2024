#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> table[i][j];
        }
    }

    int result = INT_MAX;
    for (int col = 0; col < m; ++col) {
        int columnMax = INT_MIN;
        for (int row = 0; row < n; ++row) {
            columnMax = max(columnMax, table[row][col]);
        }
        result = min(result, columnMax);
    }

    cout << result << endl;
    return 0;
}