#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M, x, y;
    cin >> N >> M;
    cin >> x >> y;

    x--;
    y--;

    vector<vector<int>> map(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = abs(i - x) + abs(j - y);
        }
    }

    int maxHeight = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            maxHeight = max(maxHeight, map[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            map[i][j] = maxHeight - map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
