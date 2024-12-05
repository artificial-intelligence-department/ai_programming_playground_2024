#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m; 
    cin >> x >> y; 
    x--; y--; 

    vector<vector<int>> height(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    height[x][y] = 0;
    q.push({x, y});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && height[nx][ny] == -1) {
                height[nx][ny] = height[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    int max_height = height[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            max_height = max(max_height, height[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            height[i][j] = max_height - height[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << height[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
