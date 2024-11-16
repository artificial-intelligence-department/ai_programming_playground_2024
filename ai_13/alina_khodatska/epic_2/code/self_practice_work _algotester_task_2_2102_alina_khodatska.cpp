#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> field(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    vector<int> rowSum(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            rowSum[i] += field[i][j];
        }
    }

    vector<int> colSum(m, 0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            colSum[j] += field[i][j];
        }
    }

    int maxFlowers = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int totalFlowers = rowSum[i] + colSum[j] - field[i][j];
            maxFlowers = max(maxFlowers, totalFlowers);
        }
    }

    cout << maxFlowers << endl;

    return 0;
}
