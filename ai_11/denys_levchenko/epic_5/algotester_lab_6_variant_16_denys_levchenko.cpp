#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool validCoordinates(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void addPawnAttacks(vector<set<char>>& attacks, int x, int y) {
    if (validCoordinates(x + 1, y - 1)) attacks[(x + 1) * 8 + (y - 1)].insert('P');
    if (validCoordinates(x + 1, y + 1)) attacks[(x + 1) * 8 + (y + 1)].insert('P');
}

void addRookAttacks(vector<set<char>>& attacks, int x, int y, char piece) {
    for (int i = 0; i < 8; i++) {
        if (i != y) attacks[x * 8 + i].insert(piece); 
        if (i != x) attacks[i * 8 + y].insert(piece); 
    }
}

void addBishopAttacks(vector<set<char>>& attacks, int x, int y, char piece) {
    for (int i = -7; i <= 7; i++) {
        if (i != 0) {
            if (validCoordinates(x + i, y + i)) attacks[(x + i) * 8 + (y + i)].insert(piece); 
            if (validCoordinates(x + i, y - i)) attacks[(x + i) * 8 + (y - i)].insert(piece);
        }
    }
}

void addKnightAttacks(vector<set<char>>& attacks, int x, int y) { 
    int knightMoves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    for (auto& move : knightMoves) {
        int x1 = x + move[0], y1 = y + move[1];
        if (validCoordinates(x1, y1)) attacks[x1 * 8 + y1].insert('N');
    }
}

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

int main(){
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<set<char>> attacks(64);

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
                case 'Q':  //queen = rook + bishop
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
    for(int i = 0; Q-i > 0; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        char cell = board[x][y];
        if (cell != 'O') {
            cout << "X\n";
        } else {
            if (attacks[x * 8 + y].empty()) {
                cout << "O\n";
            } else {
                vector<char> attackers(attacks[x * 8 + y].begin(), attacks[x * 8 + y].end());
                sort(attackers.begin(), attackers.end());
                for (char attacker : attackers) {
                    cout << attacker;
                }
                cout << "\n";
            }
        }
    }
}