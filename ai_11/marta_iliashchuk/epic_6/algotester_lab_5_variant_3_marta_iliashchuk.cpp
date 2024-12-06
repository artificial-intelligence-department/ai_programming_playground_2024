#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M, N, x, y;
    cin >> N >> M >> y >> x;

    vector<vector<int>> matrix(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = i + j;
        }
    }

    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < N; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for (int dy = -y + 1; dy < N - y + 1; dy++) {
        for (int dx = -x + 1; dx < M - x + 1; dx++) {
            int ny = y - 1 + dy;
            int nx = x - 1 + dx;

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                matrix[ny][nx] = matrix[y - 1][x - 1] - abs(dy) - abs(dx);
            }
        }
    }

    int minimum = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            minimum = min(minimum, matrix[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = matrix[i][j] + abs(minimum);
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
