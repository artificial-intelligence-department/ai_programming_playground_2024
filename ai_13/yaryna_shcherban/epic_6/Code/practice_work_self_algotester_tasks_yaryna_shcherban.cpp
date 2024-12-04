#include <iostream>
#include <vector>
#include <string>

using namespace std;

void simulateEarthquake(vector<string>& cave, int N, int M) {
    for (int col = 0; col < M; ++col) {
        int emptyRow = N - 1; 
        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                emptyRow = row - 1; 
            } else if (cave[row][col] == 'S') {
                cave[row][col] = 'O';
                if (emptyRow >= 0) {
                    cave[emptyRow][col] = 'S';
                    --emptyRow;
                }
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    simulateEarthquake(cave, N, M);

    for (const auto& row : cave) {
        cout << row << endl;
    }

    return 0;
}