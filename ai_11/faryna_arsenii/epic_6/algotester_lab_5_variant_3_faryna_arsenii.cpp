#include <iostream>
#include <vector>
#include <queue> // for queue
#include <algorithm> // for max

using namespace std;

// left, right, up, down
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int N, M;
    cin >> N >> M;
    int x, y;
    cin >> x >> y;

    x--; 
    y--;

    // create map
    vector<vector<int>> Mountain(N, vector<int>(M, -1));

    // BFS
    queue<pair<int, int>> queue;
    queue.push({x, y});
    Mountain[x][y] = 0;

    while (!queue.empty()) {
        auto [cx, cy] = queue.front();
        queue.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && Mountain[nx][ny] == -1) {
                Mountain[nx][ny] = Mountain[cx][cy] + 1;
                queue.push({nx, ny});
            }
        }
    }

    int height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            height = max(height, Mountain[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Mountain[i][j] = height - Mountain[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Mountain[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
