#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int directionsX[] = {-1, 1, 0, 0};
const int directionsY[] = {0, 0, -1, 1};

int main() {
    int N, M;
    cin >> N >> M;
    int startX, startY;
    cin >> startX >> startY;

    startX--; 
    startY--;

    vector<vector<int>> map(N, vector<int>(M, -1));

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push({startX, startY});
    map[startX][startY] = 0;

    while (!bfsQueue.empty()) {
        auto [currentX, currentY] = bfsQueue.front();
        bfsQueue.pop();

        for (int direction = 0; direction < 4; direction++) {
            int nextX = currentX + directionsX[direction];
            int nextY = currentY + directionsY[direction];

            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && map[nextX][nextY] == -1) {
                map[nextX][nextY] = map[currentX][currentY] + 1;
                bfsQueue.push({nextX, nextY});
            }
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
