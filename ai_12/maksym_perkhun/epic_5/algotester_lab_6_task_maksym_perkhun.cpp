#include <unordered_set>
#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct kord {
    int x;
    int y;
};

bool isInDesk(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}
string checkAttack(int x, int y, char desk[8][8]) {
    if (desk[x][y] != 'O') return "X";
    unordered_set<char> attackers;


    for (int i = 1; i < 8; i++) {
        if (isInDesk(x - i, y + i) && (desk[x - i][y + i] == 'B' || desk[x - i][y + i] == 'Q')) attackers.insert(desk[x - i][y + i]);
        if (isInDesk(x - i, y - i) && (desk[x - i][y - i] == 'B' || desk[x - i][y - i] == 'Q')) attackers.insert(desk[x - i][y - i]);
        if (isInDesk(x + i, y - i) && (desk[x + i][y - i] == 'B' || desk[x + i][y - i] == 'Q')) attackers.insert(desk[x + i][y - i]);
        if (isInDesk(x + i, y + i) && (desk[x + i][y + i] == 'B' || desk[x + i][y + i] == 'Q')) attackers.insert(desk[x + i][y + i]);
    }


    int kingMoves[8][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    for (auto &move : kingMoves) {
        if (isInDesk(x + move[0], y + move[1]) && desk[x + move[0]][y + move[1]] == 'K') {
            attackers.insert('K');
        }
    }


    int knightMoves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (auto &move : knightMoves) {
        if (isInDesk(x + move[0], y + move[1]) && desk[x + move[0]][y + move[1]] == 'N') {
            attackers.insert('N');
        }
    }


    if (isInDesk(x - 1, y - 1) && desk[x - 1][y - 1] == 'P') attackers.insert('P');
    if (isInDesk(x - 1, y + 1) && desk[x - 1][y + 1] == 'P') attackers.insert('P');

    for (int i = 1; i < 8; i++) {
        if (isInDesk(x - i, y) && (desk[x - i][y] == 'R' || desk[x - i][y] == 'Q')) attackers.insert(desk[x - i][y]);
        if (isInDesk(x + i, y) && (desk[x + i][y] == 'R' || desk[x + i][y] == 'Q')) attackers.insert(desk[x + i][y]);
        if (isInDesk(x, y - i) && (desk[x][y - i] == 'R' || desk[x][y - i] == 'Q')) attackers.insert(desk[x][y - i]);
        if (isInDesk(x, y + i) && (desk[x][y + i] == 'R' || desk[x][y + i] == 'Q')) attackers.insert(desk[x][y + i]);
    }

    string res(attackers.begin(), attackers.end());
    sort(res.begin(), res.end());
    return res.empty() ? "O" : res;
}


int main() {
    char desk[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> desk[i][j];
        }
    }
    int n;
    cin >> n;
    vector<kord> requests(n);
    for(int i = 0; i < n; i++){
        cin >> requests[i].x >> requests[i].y;
    }
    for(int i = 0; i < n; i++){
        cout << checkAttack(requests[i].x - 1, requests[i].y - 1, desk) << endl;
    }

    return 0;
}
