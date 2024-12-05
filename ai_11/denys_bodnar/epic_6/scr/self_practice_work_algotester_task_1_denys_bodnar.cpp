#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, y;

    cin >> n >> m;
    cin >> x >> y;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    x--;
    y--;

    vector<vector<int>> heights(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    q.push({x, y});
    heights[x][y] = 0;
    int maxHeight = 0;

    while (!q.empty()) {
        auto [currentX, currentY] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int neighborX = currentX + dx[i];
            int neighborY = currentY + dy[i];

            if (neighborX >= 0 && neighborX < n && neighborY >= 0 && neighborY < m && heights[neighborX][neighborY] == -1) {
                heights[neighborX][neighborY] = heights[currentX][currentY] + 1;
                maxHeight = max(maxHeight, heights[neighborX][neighborY]);
                q.push({neighborX, neighborY});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << maxHeight - heights[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
