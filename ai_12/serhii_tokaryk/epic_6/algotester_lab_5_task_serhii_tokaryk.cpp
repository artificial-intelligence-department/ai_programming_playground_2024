#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    x--; y--;

    vector<vector<int>> mount(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    q.push({x, y});

    int max_height = max(x, N - 1 - x) + max(y, M - 1 - y);
    mount[x][y] = max_height;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && mount[nx][ny] == -1) {
                mount[nx][ny] = mount[cx][cy] - 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mount[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
