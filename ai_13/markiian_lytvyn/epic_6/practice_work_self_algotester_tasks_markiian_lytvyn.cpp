#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;

    x--; 
    y--;

    vector<vector<int>> h(N, vector<int>(M, -1));
    queue<pair<int, int>> a;

    a.push({x, y});
    int max_h = max(x, N - 1 - x) + max(y, M - 1 - y);
    h[x][y] = max_h;
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};
    while (!a.empty()) {
        auto [cx, cy] = a.front();
        a.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && h[nx][ny] == -1) {
                h[nx][ny] = h[cx][cy] - 1;
                if (h[nx][ny] > 0) {
                    a.push({nx, ny});
                }
            }
        }
    }
    for (const auto& row : h) {
        for (int b : row) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}
