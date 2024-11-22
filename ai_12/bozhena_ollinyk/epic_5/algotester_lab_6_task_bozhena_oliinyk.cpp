#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm> 

using namespace std;

struct Figure {
    char name;
    int x;
    int y;
};

const char figuresType[] = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'};

int cellСheck(Figure &f, int x, int y) {
    if (f.x == x && f.y == y)
        return 6;
    switch (f.name) {
    case 'P':
        if (f.x == x - 1 && abs(f.y - y) == 1)
            return 0;
        break;
    case 'R':
        if (f.x == x || f.y == y)
            return 1;
        break;
    case 'N':
        if ((abs(f.x - x) == 2 && abs(f.y - y) == 1) || (abs(f.x - x) == 1 && abs(f.y - y) == 2))
            return 2;
        break;
    case 'B':
        if (abs(f.x - x) == abs(f.y - y))
            return 3;
        break;
    case 'K':
        if (abs(f.x - x) <= 1 && abs(f.y - y) <= 1)
            return 4;
        break;
    case 'Q':
        if (f.x == x || f.y == y || abs(f.x - x) == abs(f.y - y))
            return 5;
        break;
    default:
        break;
    }
    return -1;
}

int main() {
    Figure figures[64];
    int figuresCount = 0;

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != figuresType[7]) {
                figures[figuresCount++] = {row[j], i + 1, j + 1};
            }
        }
    }

    int Q;
    cin >> Q;
    char answer[100][7];
    int answerSizes[100] = {0};

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        bool empty = true;
        bool occypied = false;
        bool found[6] = {false};

        for (int i = 0; i < figuresCount; i++) {
            int index = cellСheck(figures[i], x, y);
            if (index >= 0 && index <= 5) {
                found[index] = true;
                empty = false;
            } else if (index == 6) {
                empty = false;
                occypied = true;
            }
        }

        if (occypied) {
            answer[q][0] = figuresType[6];
            answerSizes[q] = 1;
        } else if (empty) {
            answer[q][0] = figuresType[7];
            answerSizes[q] = 1;
        } else {
            int size = 0;
            for (int i = 0; i < 6; i++) {
                if (found[i]) {
                    answer[q][size++] = figuresType[i];
                }
            }
            answerSizes[q] = size;
            sort(answer[q], answer[q] + size);
        }
    }

    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < answerSizes[q]; i++) {
            cout << answer[q][i];
        }
        cout << endl;
    }

    return 0;
}
