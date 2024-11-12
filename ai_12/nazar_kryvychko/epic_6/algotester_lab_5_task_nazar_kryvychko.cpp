#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int main() {
    int N, M;
    cin >> N >> M;
    int x, y;
    cin >> x >> y;
    x--; y--;

    vector<vector<int>> height(N, vector<int>(M, -1));

    queue<pair<int, int>> q;
    q.push({ x, y });
    height[x][y] = 0;

    while (!q.empty()) {
        auto fEl = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = fEl.first + dx[i];
            int ny = fEl.second + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && height[nx][ny] == -1) {
                height[nx][ny] = height[fEl.first][fEl.second] + 1;
                q.push({ nx, ny });
            }
        }
    }

    int maxHeight = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            maxHeight = max(maxHeight, height[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << maxHeight - height[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

