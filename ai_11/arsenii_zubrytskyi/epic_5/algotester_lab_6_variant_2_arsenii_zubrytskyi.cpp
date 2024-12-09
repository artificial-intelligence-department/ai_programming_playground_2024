#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

// Константа для розміру дошки
const int BOARD_SIZE = 8;

// Функція перевірки атаки фігури
bool isUnderAttack(char piece, int px, int py, int tx, int ty) {
    if (piece == 'R') {
        return px == tx || py == ty;
    }
    if (piece == 'B') {
        return abs(px - tx) == abs(py - ty);
    }
    if (piece == 'N') {
        return (abs(px - tx) == 2 && abs(py - ty) == 1) || (abs(px - tx) == 1 && abs(py - ty) == 2);
    }
    if (piece == 'P') {
        return px + 1 == tx && abs(py - ty) == 1;
    }
    if (piece == 'K') {
        return max(abs(px - tx), abs(py - ty)) == 1;
    }
    if (piece == 'Q') {
        return px == tx || py == ty || abs(px - tx) == abs(py - ty);
    }
    return false;
}

// Основна функція
int main() {
    vector<string> chessboard(BOARD_SIZE);

    // Зчитування стану шахової дошки
    for (int i = 0; i < BOARD_SIZE; i++) {
        cin >> chessboard[i];
    }

    int queries;
    cin >> queries;

    vector<string> outputs(queries);

    // Обробка кожного запиту
    for (int q = 0; q < queries; q++) {
        int x, y;
        cin >> x >> y;
        x--, y--; // Перехід до 0-індексації

        // Якщо клітинка зайнята фігурою
        if (chessboard[x][y] != 'O') {
            outputs[q] = "X";
            continue;
        }

        set<char> attackers;
        // Перевіряємо, які фігури атакують цільову клітинку
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                char piece = chessboard[i][j];
                if (piece != 'O' && isUnderAttack(piece, i, j, x, y)) {
                    attackers.insert(piece);
                }
            }
        }

        // Формуємо результат
        if (attackers.empty()) {
            outputs[q] = "O";
        } else {
            string attackList(attackers.begin(), attackers.end());
            outputs[q] = attackList;
        }
    }

    // Вивід результатів
    for (const string& output : outputs) {
        cout << output << endl;
    }

    return 0;
}
