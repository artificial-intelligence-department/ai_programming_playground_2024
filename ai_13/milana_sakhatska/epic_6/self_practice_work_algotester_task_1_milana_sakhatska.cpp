#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// Перевірка координат
bool validCoordinates(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

// Додавання атак пішаків
void addPawnAttacks(vector<set<char>>& attacks, int x, int y) {
    if (validCoordinates(x + 1, y - 1)) attacks[(x + 1) * 8 + (y - 1)].insert('P');
    if (validCoordinates(x + 1, y + 1)) attacks[(x + 1) * 8 + (y + 1)].insert('P');
}

// Додавання атак тури
void addRookAttacks(vector<set<char>>& attacks, int x, int y, char piece) {
    for (int i = 0; i < 8; i++) {
        if (i != y) attacks[x * 8 + i].insert(piece); 
        if (i != x) attacks[i * 8 + y].insert(piece); 
    }
}

// Додавання атак слона
void addBishopAttacks(vector<set<char>>& attacks, int x, int y, char piece) {
    for (int i = -7; i <= 7; i++) {
        if (i != 0) {
            if (validCoordinates(x + i, y + i)) attacks[(x + i) * 8 + (y + i)].insert(piece); 
            if (validCoordinates(x + i, y - i)) attacks[(x + i) * 8 + (y - i)].insert(piece);
        }
    }
}

// Додавання атак коня
void addKnightAttacks(vector<set<char>>& attacks, int x, int y) { 
    int knightMoves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    for (auto& move : knightMoves) {
        int x1 = x + move[0], y1 = y + move[1];
        if (validCoordinates(x1, y1)) attacks[x1 * 8 + y1].insert('N');
    }
}

// Додавання атак короля
void addKingAttacks(vector<set<char>>& attacks, int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                int x1 = x + dx, y1 = y + dy;
                if (validCoordinates(x1, y1)) attacks[x1 * 8 + y1].insert('K');
            }
        }
    }
}

// Основна функція
int main() {
    vector<string> board(8);  // Вхідна дошка
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<set<char>> attacks(64);  // Атаки на кожну клітинку

    // Додавання атак для кожної фігури на дошці
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char piece = board[i][j];
            switch (piece) {
                case 'P':
                    addPawnAttacks(attacks, i, j);
                    break;
                case 'R':
                    addRookAttacks(attacks, i, j, 'R');
                    break;
                case 'N':
                    addKnightAttacks(attacks, i, j);
                    break;
                case 'B':
                    addBishopAttacks(attacks, i, j, 'B');
                    break;
                case 'K':
                    addKingAttacks(attacks, i, j);
                    break;
                case 'Q':  
                    addRookAttacks(attacks, i, j, 'Q');
                    addBishopAttacks(attacks, i, j, 'Q');
                    break;
                default:
                    break;
            }
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;
        x--; y--; // Перехід до 0-індексації

        char cell = board[x][y];
        if (cell != 'O') {  // Якщо клітинка зайнята фігурою
            cout << "X\n";
        } else {  // Якщо клітинка порожня
            if (attacks[x * 8 + y].empty()) {  // Ніхто не атакує
                cout << "O\n";
            } else {  // Є атакуючі фігури
                vector<char> attackers(attacks[x * 8 + y].begin(), attacks[x * 8 + y].end());
                sort(attackers.begin(), attackers.end());
                for (char attacker : attackers) {
                    cout << attacker;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
