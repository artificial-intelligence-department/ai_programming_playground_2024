#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define BOARD_SIZE 8

// Функція перевірки, чи може пішак атакувати клітинку
bool canAttackPawn(int x, int y, int px, int py) {
    return (px == x + 1 && (py == y - 1 || py == y + 1)); // Пішак атакує вниз по діагоналях
}

// Функція для перевірки атаки тура
bool canAttackRook(int x, int y, int rx, int ry, const vector<string>& board) {
    if (x != rx && y != ry) return false; // Тура може атакувати лише по вертикалі чи горизонталі
    if (x == rx) {
        // Перевіряємо, чи є фігури між турами по горизонталі
        int start = min(y, ry) + 1;
        int end = max(y, ry);
        for (int j = start; j < end; ++j) {
            if (board[x][j] != 'O') return false; // Фігура між турами блокує атаку
        }
    } else if (y == ry) {
        // Перевіряємо по вертикалі
        int start = min(x, rx) + 1;
        int end = max(x, rx);
        for (int i = start; i < end; ++i) {
            if (board[i][y] != 'O') return false; // Фігура між турами блокує атаку
        }
    }
    return true;
}

// Функція для перевірки атаки слона
bool canAttackBishop(int x, int y, int bx, int by, const vector<string>& board) {
    if (abs(x - bx) != abs(y - by)) return false; // Слон може атакувати лише по діагоналях
    int dx = (bx > x) ? 1 : -1;
    int dy = (by > y) ? 1 : -1;
    int i = x + dx, j = y + dy;
    while (i != bx && j != by) {
        if (board[i][j] != 'O') return false; // Фігура між слоном і клітинкою блокує атаку
        i += dx;
        j += dy;
    }
    return true;
}

// Функція для перевірки атаки конем
bool canAttackKnight(int x, int y, int nx, int ny) {
    return (abs(x - nx) == 2 && abs(y - ny) == 1) || (abs(x - nx) == 1 && abs(y - ny) == 2); // Кінь може атакувати в "букву Г"
}

// Функція для перевірки атаки королем
bool canAttackKing(int x, int y, int kx, int ky) {
    return abs(x - kx) <= 1 && abs(y - ky) <= 1; // Король атакує на одну клітинку у будь-якому напрямку
}

// Функція для перевірки атаки королевою
bool canAttackQueen(int x, int y, int qx, int qy, const vector<string>& board) {
    return canAttackRook(x, y, qx, qy, board) || canAttackBishop(x, y, qx, qy, board); // Королева атакує як тура і слон
}

// Основна функція
int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    int Q;
    cin >> Q;
    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].first >> queries[i].second;
        queries[i].first--;  // Перехід до індексації з нуля
        queries[i].second--;
    }

    // Для кожного запиту визначаємо фігури, що атакують клітинку
    for (auto& query : queries) {
        int x = query.first;
        int y = query.second;
        
        // Якщо в клітинці вже є фігура
        if (board[x][y] != 'O') {
            cout << "X" << endl;
            continue;
        }

        set<char> attackingFigures;

        // Перевіряємо атаки від усіх фігур на дошці
        for (int i = 0; i < BOARD_SIZE; ++i) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                if (board[i][j] == 'O') continue; // Якщо клітинка пуста

                // Перевірка на атаку кожною фігурою
                if (board[i][j] == 'P' && canAttackPawn(x, y, i, j)) attackingFigures.insert('P');
                if (board[i][j] == 'R' && canAttackRook(x, y, i, j, board)) attackingFigures.insert('R');
                if (board[i][j] == 'N' && canAttackKnight(x, y, i, j)) attackingFigures.insert('N');
                if (board[i][j] == 'B' && canAttackBishop(x, y, i, j, board)) attackingFigures.insert('B');
                if (board[i][j] == 'K' && canAttackKing(x, y, i, j)) attackingFigures.insert('K');
                if (board[i][j] == 'Q' && canAttackQueen(x, y, i, j, board)) attackingFigures.insert('Q');
            }
        }

        if (attackingFigures.empty()) {
            cout << "O" << endl;
        } else {
            for (char c : attackingFigures) {
                cout << c;
            }
            cout << endl;
        }
    }

    return 0;
}
