#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

bool attacks(char figure, int fx, int fy, int tx, int ty) {
    switch (figure) {
    case 'P': return fx == tx - 1 && abs(fy - ty) == 1;               // Пішак
    case 'R': return fx == tx || fy == ty;                           // Тура
    case 'N': return (abs(fx - tx) == 2 && abs(fy - ty) == 1) || 
                     (abs(fx - tx) == 1 && abs(fy - ty) == 2);       // Кінь
    case 'B': return abs(fx - tx) == abs(fy - ty);                   // Слон
    case 'K': return abs(fx - tx) <= 1 && abs(fy - ty) <= 1;         // Король
    case 'Q': return fx == tx || fy == ty || 
                     abs(fx - tx) == abs(fy - ty);                   // Ферзь
    default: return false;
    }
}

int main() {
    vector<pair<char, pair<int, int>>> figures; 

    for (int i = 1; i <= 8; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < 8; ++j) {
            if (row[j] != 'O') { 
                figures.push_back({row[j], {i, j + 1}});
            }
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int x, y;
        cin >> x >> y;

        set<char> attackers;
        bool occupied = false;

        for (auto &[figure, coords] : figures) {
            auto &[fx, fy] = coords;
            if (fx == x && fy == y) {
                occupied = true;
                break;
            }
            if (attacks(figure, fx, fy, x, y)) {
                attackers.insert(figure);
            }
        }

        if (occupied) {
            cout << 'X' << endl; 
        } else if (attackers.empty()) {
            cout << 'O' << endl; 
        } else {
            for (char c : attackers) {
                cout << c; 
            }
            cout << endl;
        }
    }

    return 0;
}
