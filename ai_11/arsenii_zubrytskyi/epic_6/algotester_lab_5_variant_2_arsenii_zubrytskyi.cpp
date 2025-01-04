#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // Створення матриці печери
    vector<vector<char>> cave(N, vector<char>(M));
    
    // Читання вхідних даних
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }
    
    // Обробка кожного стовпця окремо
    for (int j = 0; j < M; ++j) {
        int sandPos = N - 1; // Початкова позиція для піску, найнижча клітинка
        // Проходимо знизу вгору
        for (int i = N - 1; i >= 0; --i) {
            if (cave[i][j] == 'S') {  // Знайшли пісок
                // Переміщаємо пісок вниз до першої вільної клітинки
                cave[i][j] = 'O';
                cave[sandPos][j] = 'S';
                --sandPos;  // Знижуємо позицію для наступного піску
            } else if (cave[i][j] == 'X') {
                // Якщо зустрічаємо камінь, зупиняємо падіння піску
                sandPos = i - 1;
            }
        }
    }
    
    // Виведення результату
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
