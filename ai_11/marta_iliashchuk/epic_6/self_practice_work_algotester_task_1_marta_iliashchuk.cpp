#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> rows(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            rows[i][j] = row[j];
        }
    }

    for (int j = 0; j < M; j++) { 
        for (int i = N - 2; i >= 0; i--) {
            if (rows[i][j] == 'S') { 
                int k = i;
                while (k + 1 < N && rows[k + 1][j] == 'O') {
                    k++;  
                }
                if (k != i && rows[k][j] != 'X') {
                    rows[k][j] = 'S'; 
                    rows[i][j] = 'O'; 
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << rows[i][j];
        }
        cout << endl;
    }

    return 0;
}