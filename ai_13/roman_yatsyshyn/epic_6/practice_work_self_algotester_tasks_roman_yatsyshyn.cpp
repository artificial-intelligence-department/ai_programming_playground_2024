#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    vector<string> result(N, string(M, 'O'));

    for (int col = 0; col < M; ++col) {
        int emptyRow = N - 1;
        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                result[row][col] = 'X';
                emptyRow = row - 1;
            } else if (cave[row][col] == 'S') {
                result[emptyRow][col] = 'S';
                --emptyRow;
            }
        }
    }

    for (const auto& row : result) {
        cout << row << endl;
    }

    return 0;
}




