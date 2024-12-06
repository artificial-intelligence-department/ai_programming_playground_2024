//лаба 5 варіант 3(гори)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    //зменшуємо координати до 0-індексації
    x--;
    y--;

    //ініціалізуємо матриці висот
    vector<vector<int>> matrix(N, vector<int>(M, 0));

    //обчислюємо максимальної висоти
    int maxHeight = max(x, N - x - 1) + max(y, M - y - 1);

    //заповнюємо матрицю висот
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int distance = abs(x - i) + abs(y - j);
            matrix[i][j] = maxHeight - distance;
        }
    }

    //виводимо матриці висот
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << (j == M - 1 ? '\n' : ' ');
        }
    }

    return 0;
}
