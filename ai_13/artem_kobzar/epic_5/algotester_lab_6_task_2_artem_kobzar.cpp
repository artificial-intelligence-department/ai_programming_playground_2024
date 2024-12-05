#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool isValidCell(int row, int col) {
    return row >= 0 && row < 8 && col >= 0 && col < 8;
}

void markPawnAttacks(vector<unordered_set<char>>& attackMap, int row, int col) {
    if (isValidCell(row + 1, col - 1)) attackMap[(row + 1) * 8 + (col - 1)].insert('P');
    if (isValidCell(row + 1, col + 1)) attackMap[(row + 1) * 8 + (col + 1)].insert('P');
}

void markRookAttacks(vector<unordered_set<char>>& attackMap, int row, int col, char rookType) {
    for (int i = 0; i < 8; ++i) {
        if (i != col) attackMap[row * 8 + i].insert(rookType);
        if (i != row) attackMap[i * 8 + col].insert(rookType);
    }
}

void markBishopAttacks(vector<unordered_set<char>>& attackMap, int row, int col, char bishopType) {
    for (int i = 1; i < 8; ++i) {
        if (isValidCell(row + i, col + i)) attackMap[(row + i) * 8 + (col + i)].insert(bishopType);
        if (isValidCell(row + i, col - i)) attackMap[(row + i) * 8 + (col - i)].insert(bishopType);
        if (isValidCell(row - i, col + i)) attackMap[(row - i) * 8 + (col + i)].insert(bishopType);
        if (isValidCell(row - i, col - i)) attackMap[(row - i) * 8 + (col - i)].insert(bishopType);
    }
}

void markKnightAttacks(vector<unordered_set<char>>& attackMap, int row, int col) {
    int knightMoves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};
    for (auto& move : knightMoves) {
        int newRow = row + move[0], newCol = col + move[1];
        if (isValidCell(newRow, newCol)) attackMap[newRow * 8 + newCol].insert('N');
    }
}

void markKingAttacks(vector<unordered_set<char>>& attackMap, int row, int col) {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx != 0 || dy != 0) {
                int newRow = row + dx, newCol = col + dy;
                if (isValidCell(newRow, newCol)) attackMap[newRow * 8 + newCol].insert('K');
            }
        }
    }
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    vector<unordered_set<char>> attackMap(64);

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            char piece = board[row][col];
            switch (piece) {
                case 'P': markPawnAttacks(attackMap, row, col); break;
                case 'R': markRookAttacks(attackMap, row, col, 'R'); break;
                case 'B': markBishopAttacks(attackMap, row, col, 'B'); break;
                case 'N': markKnightAttacks(attackMap, row, col); break;
                case 'K': markKingAttacks(attackMap, row, col); break;
                case 'Q': 
                        markRookAttacks(attackMap, row, col, 'Q');
                        markBishopAttacks(attackMap, row, col, 'Q');
                    break;
                default: break;
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        if (board[x][y] != 'O') {
            cout << "X\n";
        } else if (attackMap[x * 8 + y].empty()) {
            cout << "O\n";
        } else {
            vector<char> attackers(attackMap[x * 8 + y].begin(), attackMap[x * 8 + y].end());
            sort(attackers.begin(), attackers.end());
            for (char attacker : attackers) {
                cout << attacker;
            }
            cout << "\n";
        }
    }
    return 0;
}
