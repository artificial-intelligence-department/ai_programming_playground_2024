#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N,M, x, y;
    cin >> N >> M;
    cin >> x >> y;
    int max = 0;
    if(x > N/2) {      //шукаємо найбільшу відстань до кутів
        max += x - 1;
    } else {
        max += N - x;
    }
    if(y > M/2) {
        max += y - 1;
    } else {
        max += M - y;
    }

    vector<vector<int>> map(N, vector<int>(M, -1));

    queue<pair<int,int>> q;
    map[x - 1][y - 1] = max;
    q.push({x - 1, y - 1});

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == -1) {
                map[nx][ny] = map[cx][cy] - 1;
                q.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}