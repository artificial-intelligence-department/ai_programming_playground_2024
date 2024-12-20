#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

char board[8][8];

// Перевірка на валідні координати
bool validCoordinate(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void attackPawn(int x, int y, set<char>& attackers) {
    if (validCoordinate(x - 1, y - 1) && board[x - 1][y - 1] == 'P') {
        attackers.insert('P');  // Pawn attacks from upper left
    }

    if (validCoordinate(x - 1, y + 1) && board[x - 1][y + 1] == 'P') {
        attackers.insert('P');  // Pawn attacks from upper right
    }
}


// Атака конем
void attackKnight(int x, int y, set<char>& attackers) {
    vector<pair<int, int>> knightMoves = {
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
        {-1, -2}, {1, -2}, {-1, 2}, {1, 2}
    };

    for (auto move : knightMoves) {
        int new_x = x + move.first;
        int new_y = y + move.second;
        if (validCoordinate(new_x, new_y) && board[new_x][new_y] == 'N') {
            attackers.insert('N');
        }
    }
}

void attackBishop(int x, int y, set<char>& attackers) {
    vector<pair<int, int>> directions = { {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

    for (auto dir : directions) {
        int dx = dir.first, dy = dir.second;
        for (int i = 1; i < 8; i++) {
            int new_x = x + i * dx;
            int new_y = y + i * dy;

            if (!validCoordinate(new_x, new_y)) break;  // Stop if out of bounds

            char piece = board[new_x][new_y];
            if (piece == 'Q' || piece == 'B') {
                attackers.insert(piece);
            }
        }
    }
}

void attackRook(int x, int y, set<char>& attackers) {
    for (int col = 0; col < 8; col++) {
        if (col != y) {
            if (board[x][col] == 'R' || board[x][col] == 'Q') {
                attackers.insert(board[x][col]);
                break;
            }
        }
    }

    for (int row = 0; row < 8; row++) {
        if (row != x) {
            if (board[row][y] == 'R' || board[row][y] == 'Q') {
                attackers.insert(board[row][y]);
                break;
            }
        }
    }
}

// Атака королевою (поєднання тури та слона)
void attackQueen(int x, int y, set<char>& attackers) {
    attackRook(x, y, attackers);   // Check rook-like movements
    attackBishop(x, y, attackers); // Check bishop-like movements
}
// Атака королем
void attackKing(int x, int y, set<char>& attackers) {
    // Можливі напрямки для короля (по вертикалі, горизонталі і діагоналях)
    vector<pair<int, int>> kingMoves = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
        {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };

    // Перевіряємо кожен напрямок
    for (auto move : kingMoves) {
        int new_x = x + move.first;
        int new_y = y + move.second;

        // Перевірка, чи координати в межах дошки та чи є на новому полі король
        if (validCoordinate(new_x, new_y) && board[new_x][new_y] == 'K') {
            attackers.insert('K');  // Додаємо короля до атаки
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    int Q;
    cin >> Q;
    for(int i = 0; Q-i > 0; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        set<char> attackers;

        if (board[x][y] != 'O') {
            cout << "X" << endl;
        }
        else {
            attackPawn(x, y, attackers);
            attackKnight(x, y, attackers);
            attackBishop(x, y, attackers);
            attackRook(x, y, attackers);
            attackQueen(x, y, attackers);
            attackKing(x, y, attackers);

            if (attackers.empty()) {
                cout << "O" << endl;
            }
            else {
                for (char c : attackers) {
                    cout << c;
                }
                cout << endl;
            }
        }
    }

    return 0;
}
