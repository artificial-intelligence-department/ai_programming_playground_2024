#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int col = 0; col < m; col++) {
        int emptyRow = n - 1;
        for (int row = n - 1; row >= 0; row--) {
            if (grid[row][col] == '*') {
                grid[row][col] = '.';
                grid[emptyRow][col] = '*';
                emptyRow--;
            }
        }
    }

    for (const string &row : grid) {
        cout << row << endl;
    }

    return 0;
}
