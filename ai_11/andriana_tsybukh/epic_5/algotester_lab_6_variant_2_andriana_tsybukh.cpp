#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool isValid(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void addAttacker(set<char>& attackers, char figure) {
    attackers.insert(figure);
}

string checkCell(const vector<string>& board, int x, int y) {
    if (board[x][y] != 'O') {
        return "X";
    }
    
    set<char> attackers;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char figure = board[i][j];
            if (figure == 'O') continue;

            switch (figure) {
                case 'P': // пішаки
                    if (isValid(i + 1, j - 1) && i + 1 == x && j - 1 == y) 
                        addAttacker(attackers, 'P');
                    if (isValid(i + 1, j + 1) && i + 1 == x && j + 1 == y) 
                        addAttacker(attackers, 'P');
                    break;
                case 'R': // тура
                    if (i == x || j == y) 
                        addAttacker(attackers, 'R');
                    break;
                case 'N': // кінь
                    if (abs(i - x) == 2 && abs(j - y) == 1) 
                        addAttacker(attackers, 'N');
                    if (abs(i - x) == 1 && abs(j - y) == 2) 
                        addAttacker(attackers, 'N');
                    break;
                case 'B': // слон
                    if (abs(i - x) == abs(j - y)) 
                        addAttacker(attackers, 'B');
                    break;
                case 'K': // король
                    if (abs(i - x) <= 1 && abs(j - y) <= 1) 
                        addAttacker(attackers, 'K');
                    break;
                case 'Q': // ферзь
                    if (i == x || j == y || abs(i - x) == abs(j - y)) 
                        addAttacker(attackers, 'Q');
                    break;
            }
        }
    }

    if (attackers.empty()) {
        return "O";
    }

    string result(attackers.begin(), attackers.end());
    return result;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        cout << checkCell(board, x, y) << endl;
    }

    return 0;
}
