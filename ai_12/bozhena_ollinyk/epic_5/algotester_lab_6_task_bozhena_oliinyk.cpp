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

const char figures_type[] = {'P', 'R', 'N', 'B', 'K', 'Q', 'X', 'O'};

int cell_check(Figure &f, int x, int y) {
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
    int figures_count = 0;

    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < row.size(); j++) {
            if (row[j] != figures_type[7]) {
                figures[figures_count++] = {row[j], i + 1, j + 1};
            }
        }
    }

    int Q;
    cin >> Q;
    char answer[100][7];
    int answer_sizes[100] = {0};

    for (int q = 0; q < Q; q++) {
        int x, y;
        cin >> x >> y;

        bool case1 = true;
        bool case2 = false;
        bool found[6] = {false};

        for (int i = 0; i < figures_count; i++) {
            int index = cell_check(figures[i], x, y);
            if (index >= 0 && index <= 5) {
                found[index] = true;
                case1 = false;
            } else if (index == 6) {
                case1 = false;
                case2 = true;
            }
        }

        if (case2) {
            answer[q][0] = figures_type[6];
            answer_sizes[q] = 1;
        } else if (case1) {
            answer[q][0] = figures_type[7];
            answer_sizes[q] = 1;
        } else {
            int size = 0;
            for (int i = 0; i < 6; i++) {
                if (found[i]) {
                    answer[q][size++] = figures_type[i];
                }
            }
            answer_sizes[q] = size;
            sort(answer[q], answer[q] + size);
        }
    }

    for (int q = 0; q < Q; q++) {
        for (int i = 0; i < answer_sizes[q]; i++) {
            cout << answer[q][i];
        }
        cout << endl;
    }

    return 0;
}
