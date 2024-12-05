#include <iostream>
#include <vector>
#include <string>

using namespace std;

void simulateEarthquake(vector<string>& cave, int N, int M) {
    for (int col = 0; col < M; ++col) {
        int bottom = N - 1; // Починаємо із дна стовпця

        // Проходимо знизу вгору по стовпцю
        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                // Якщо зустріли камінь, оновлюємо нове "дно" над каменем
                bottom = row - 1;
            } else if (cave[row][col] == 'S') {
                // Переміщуємо пісок на найнижчу доступну клітинку
                cave[row][col] = 'O';
                cave[bottom][col] = 'S';
                bottom--;
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);

    // Зчитування вхідних даних
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    // Симуляція землетрусу
    simulateEarthquake(cave, N, M);

    // Виведення результату
    for (const string& row : cave) {
        cout << row << endl;
    }

    return 0;
}







