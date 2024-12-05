#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> cave(n);
    for (int i = 0; i < n; ++i) cin >> cave[i];

    for (int col = 0; col < m; ++col) {
        int empty_row = n - 1;
        for (int row = n - 1; row >= 0; --row) {
            if (cave[row][col] == 'S') {
                cave[row][col] = 'O';
                cave[empty_row--][col] = 'S';
            }
            else if (cave[row][col] == 'X') {
                empty_row = row - 1;
            }
        }
    }

    for (const auto& row : cave) cout << row << "\n";

    return 0;
}
