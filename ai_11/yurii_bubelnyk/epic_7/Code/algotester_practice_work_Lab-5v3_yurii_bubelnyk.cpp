#include <iostream>
#include <vector>
#include <cstdlib> // Для abs()

using namespace std;

int main() {

    int N, M; // ініціалізація змінних типу int для умови 
    cin >> N >> M;


    if (N < 1 || N > 1000 || M < 1 || M > 1000) return 1; // перевірка меж

    int x, y;
    cin >> x >> y;

    if (x < 1 || x > N || y < 1 || y > M) return 1; // перевірка меж
    // змінюю індиксація щоб починати з початку координат
    x -= 1; 
    y -= 1;
    // змінна для відстані
    int max_distance = 0;
    // цикл для ініціалізації кожної точки або координати
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int distance = abs(i - x) + abs(j - y); // використав манхетенську форму запису відстані
            max_distance = (max_distance < distance) ? distance : max_distance; // тернарний оператор для зміни відстані
        }
    }
    // цикл для виведення значень 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int distance = abs(i - x) + abs(j - y); // знову обчислюю довжину
            cout << max_distance - distance << " "; // виводжу різницю як значення висоти гори
        }
        cout << endl;
    }


    return 0;
}
