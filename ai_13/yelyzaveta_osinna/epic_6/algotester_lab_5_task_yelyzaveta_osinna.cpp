#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N); // Матриця печери
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    // Симуляція падіння піску
    for (int col = 0; col < M; ++col) {
        int emptyRow = N - 1; // Починаємо з найнижчого рядка
        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                // Камінь блокує падіння піску
                emptyRow = row - 1;
            } else if (cave[row][col] == 'S') {
                // Пісок падає на рівень пустоти
                cave[row][col] = 'O'; // Очищаємо поточну позицію
                if (emptyRow >= 0) {
                    cave[emptyRow][col] = 'S';
                    emptyRow--;
                }
            }
        }
    }

    cout << endl;
    // Вивід результату
    for (const string& row : cave) {
        cout << row << endl;
    }

    return 0;
}
