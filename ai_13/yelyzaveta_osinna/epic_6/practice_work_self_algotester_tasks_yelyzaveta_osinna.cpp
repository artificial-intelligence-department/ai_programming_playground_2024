#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    // Обчислення максимальної висоти (відстані до найвіддаленішого кута)
    int max_height = 0;
    if (x > N / 2) {
        max_height += x - 1;  // Відстань до верхнього або нижнього краю
    } else {
        max_height += N - x;
    }
    if (y > M / 2) {
        max_height += y - 1;  // Відстань до лівого або правого краю
    } else {
        max_height += M - y;
    }

    // Матриця для висот
    vector<vector<int>> map(N, vector<int>(M, -1));

    // BFS
    queue<pair<int, int>> q;
    map[x - 1][y - 1] = max_height; // Встановлюємо висоту вершини
    q.push({x - 1, y - 1});

    // Напрямки руху: вверх, вниз, вліво, вправо
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Перевірка меж карти
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == -1) {
                map[nx][ny] = map[cx][cy] - 1; // Висота на 1 менша
                q.push({nx, ny});
            }
        }
    }

    // Вивід результату
    cout << endl;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
