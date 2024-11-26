#include <iostream>
#include <vector>
using namespace std;

void simulateSandFall(vector<vector<char>>& cave, int N, int M) {
    for (int col = 0; col < M; ++col) {
        int emptyRow = N - 1;

        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                emptyRow = row - 1;
            } else if (cave[row][col] == 'S') {
                cave[row][col] = 'O';
                cave[emptyRow][col] = 'S';
                --emptyRow;
            }
        }
    }
}

// lab 5v2
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> cave[i][j];
        }
    }

    cout << "\n-----------\n\n";
    simulateSandFall(cave, N, M);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
