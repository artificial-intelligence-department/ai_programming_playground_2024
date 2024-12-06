#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int j = 0; j < M; ++j) { 
        int row = N - 1; 
        for (int i = N - 1; i >= 0; --i) {
            if (arr[i][j] == 'X') {
                row = i - 1; 
            } else if (arr[i][j] == 'S') {
                arr[i][j] = 'O';       
                arr[row][j] = 'S'; 
                row--;             
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}
