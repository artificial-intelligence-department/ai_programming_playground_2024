#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    x--; y--;  // Adjust for 0-based indexing

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    vector<vector<int>> height(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    q.push({x, y});
    height[x][y] = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && height[nx][ny] == -1) {
                height[nx][ny] = height[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    int maxHeight = 0;
    for (const auto& row : height) {
        for (int h : row) {
            maxHeight = max(maxHeight, h);
        }
    }

    for (const auto& row : height) {
        for (int h : row) {
            cout << maxHeight - h << " ";
        }
        cout << endl;
    }

    return 0;
}