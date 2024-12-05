#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> cave(N);
    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    for (int j = 0; j < M; ++j) {
        int emptyRow = N - 1; 

        for (int i = N - 1; i >= 0; --i) {
            if (cave[i][j] == 'X') {
                emptyRow = i - 1;
            } else if (cave[i][j] == 'S') {
                cave[i][j] = 'O';
                cave[emptyRow][j] = 'S';
                --emptyRow;
            }
        }
    }

    for (const string &row : cave) {
        cout << row << endl;
    }

    return 0;
}
