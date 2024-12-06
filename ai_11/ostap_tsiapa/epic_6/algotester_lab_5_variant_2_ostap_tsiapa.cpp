#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;  // Зчитування розмірів печери
    vector<string> mystic_cave(N);  // Створення вектора рядків для зберігання печери

    for (int i = 0; i < N; ++i) {
        cin >> mystic_cave[i];  // Зчитування стану печери
    }

    // Проходження печери знизу вгору, крім останнього рядка
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j < M; ++j) {
            if (mystic_cave[i][j] == 'S') {  // Якщо знайшли пісок
                int ptr = i;
                // Знаходження найнижчої позиції, куди може впасти пісок
                for (int k = i + 1; k < N; ++k) {
                    if (mystic_cave[k][j] == 'O') {
                        ptr = k;
                    } else {
                        break;
                    }
                }
                if (ptr != i) {
                    // Заміна поточного положення піску на пустоту та опускання піску вниз
                    swap(mystic_cave[i][j], mystic_cave[ptr][j]);
                }
            }
        }
    }

    cout << endl;
    // Виведення кінцевого стану печери
    for (const string& str : mystic_cave) {
        cout << str << endl;
    }

    return 0;
}
