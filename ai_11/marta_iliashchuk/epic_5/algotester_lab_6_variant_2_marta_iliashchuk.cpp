#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool movePiece(char element, int elementX, int elementY, int x, int y) {
    switch (element) {
        case 'R': 
            return elementX == x || elementY == y;
        case 'B': 
            return abs(elementX - x) == abs(elementY - y);
        case 'N': 
            return (abs(elementX - x) == 2 && abs(elementY - y) == 1) ||
                   (abs(elementX - x) == 1 && abs(elementY - y) == 2);
        case 'P': 
            return elementX + 1 == x && abs(elementY - y) == 1;
        case 'K': 
            return abs(elementX - x) <= 1 && abs(elementY - y) <= 1;
        case 'Q': 
            return (elementX == x || elementY == y) ||
                   (abs(elementX - x) == abs(elementY - y));
        default:
            return false;
    }
}

int main() {
    vector<string> rows(8);
    
    for (int i = 0; i < 8; i++) {
        cin >> rows[i];
    }

    int Q;
    cin >> Q; 
    vector<string> result(Q);

    for (int k = 0; k < Q; k++) {
        int x, y;
        cin >> x >> y;
        x--; 
        y--;

        if (rows[x][y] != 'O') {
            result[k] = "X";
            continue;
        }

        set<char> pieces;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char element = rows[i][j];
                if (element != 'O' && movePiece(element, i, j, x, y)) {
                    pieces.insert(element);
                }
            }
        }

        if (pieces.empty()) {
            result[k] = "O"; 
        } else {
            string attackPiece(pieces.begin(), pieces.end());
            sort(attackPiece.begin(), attackPiece.end()); 
            result[k] = attackPiece;
        }
    }

    for (const string& r : result) {
        cout << r << endl;
    }

    return 0;
}