#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M >> x >> y;
    x--;
    y--;
    
    vector<vector<int>> mount(N, vector<int>(M, -1));
    queue<pair<int, int>> q;
    q.push({x,y});
    mount[x][y] = 0;

    queue<pair<int, int>> que;
    que.push({x, y});
    mount[x][y] = max(x, N - 1 - x) + max(y, M - 1 - y);

    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!que.empty()) {
        auto [cx, cy] = que.front();
        que.pop();

        for (auto& d : directions) {
            int nx = cx + d[0], ny = cy + d[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && mount[nx][ny] == -1) {
                mount[nx][ny] = mount[cx][cy] - 1;
                que.push({nx, ny});
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
