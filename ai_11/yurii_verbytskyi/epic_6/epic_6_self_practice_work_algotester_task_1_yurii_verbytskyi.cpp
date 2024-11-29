#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int x, y;
    cin >> x >> y;

    if (x < 1 || y < 1 || x > N || y > M) return 0;

    vector<vector<int>> matrix(N, vector<int>(M, -1));

    x = x - 1, y = y - 1;
    matrix[x][y] = 0;

    // всі можливі висоти
    for (int i = 0; i <= N + M; i++) {
        for (int j = 0; j < N; j++) { // по вертикалі
            for (int k = 0; k < M; k++) { // по горизанталі
                if (matrix[j][k] == i) {
                    if (j - 1 >= 0 && matrix[j - 1][k] == -1) {
                        matrix[j - 1][k] = i + 1;
                    }
                    if (j + 1 < N && matrix[j + 1][k] == -1) {
                        matrix[j + 1][k] = i + 1;
                    }
                    if (k - 1 >= 0 && matrix[j][k - 1] == -1) {
                        matrix[j][k - 1] = i + 1;
                    }
                    if (k + 1 < M && matrix[j][k + 1] == -1) {
                        matrix[j][k + 1] = i + 1;
                    }
                }
            }
        }
    }

    int max_height = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            max_height = max(max_height, matrix[i][j]);
        }
    }

    // перетворюємо висоти
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = max_height - matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
