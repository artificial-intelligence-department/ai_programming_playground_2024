#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Figure {
    char name;
    int x;
    int y;
};

const vector<char> figuresType = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'};

int cellCheck(const Figure &f, int x, int y) {
    if (f.x == x && f.y == y) return 6; // Клітинка зайнята
    int dx = abs(f.x - x);
    int dy = abs(f.y - y);
    if (f.name == 'P' && f.x == x - 1 && dy == 1) return 0;
    if (f.name == 'R' && (f.x == x || f.y == y)) return 1;
    if (f.name == 'N' && ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))) return 2;
    if (f.name == 'B' && dx == dy) return 3;
    if (f.name == 'K' && dx <= 1 && dy <= 1) return 4;
    if (f.name == 'Q' && (f.x == x || f.y == y || dx == dy)) return 5;
    return -1; 
}

int main() {
    vector<Figure> figures;

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != 'O') {
                figures.push_back({row[j], i + 1, j + 1});
            }
        }
    }

    int Q;
    cin >> Q;
    vector<vector<char>> answers(Q);

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        bool empty = true;
        bool occupied = false;
        vector<bool> found(6, false);

        for (const auto &figure : figures) {
            int index = cellCheck(figure, x, y);
            if (index == 6) {
                occupied = true;
                break;
            }
            if (index >= 0 && index <= 5) {
                found[index] = true;
                empty = false;
            }
        }

        if (occupied) {
            answers[q].push_back('X');
        } else if (empty) {
            answers[q].push_back('O');
        } else {
            for (int i = 0; i < 6; i++) {
                if (found[i]) {
                    answers[q].push_back(figuresType[i]);
                }
            }
            sort(answers[q].begin(), answers[q].end());
        }
    }

   
    for (const auto &answer : answers) {
        for (char c : answer) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
 