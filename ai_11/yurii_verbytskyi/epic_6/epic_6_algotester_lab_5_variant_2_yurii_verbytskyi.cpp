#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cave[i][j];
        }
    }

    for (int k = 0; k < N; k++) { 
        for (int i = N - 2; i >= 0; i--) { 
            for (int j = 0; j < M; j++) {
                if (cave[i][j] == 'S' && cave[i + 1][j] == 'O' && cave[i + 1][j] != 'S' && cave[i + 1][j] != 'X' ) {
                    swap(cave[i][j], cave[i + 1][j]);
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}
