#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // Читання початкового стану печери
    vector<vector<char>> cave(N, vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    // Порожня лінія між вводу та виводу
    cout << endl;

    // Обробка кожного стовпця
    for (int j = 0; j < M; j++) {
        int emptyPos = N - 1;  // Позиція, куди будемо падати пісок

        // Проходимо стовпець знизу вверх
        for (int i = N - 1; i >= 0; i--) {
            if (cave[i][j] == 'S') {
                // Якщо це пісок, поміщаємо його в поточну вільну клітинку
                cave[i][j] = 'O';  // Очищаємо поточну клітинку
                cave[emptyPos][j] = 'S';  // Поміщаємо пісок в найнижче вільне місце
                emptyPos--;  // Зсуваємо позицію для наступного піску
            }
            // Якщо це камінь, просто пропускаємо
            else if (cave[i][j] == 'X') {
                emptyPos = i - 1;  // Камінь блокує падіння піску
            }
        }
    }

    // Виведення нового стану печери
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
