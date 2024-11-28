#include <iostream>
#include <cstring> 
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int main() {
    int N, M;
    char cave[MAX_N][MAX_M + 1]; 

    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> cave[i];
    }

    for (int col = 0; col < M; ++col) {
        int empty_row = N - 1; 

        for (int row = N - 1; row >= 0; --row) {
            if (cave[row][col] == 'X') {
                empty_row = row - 1;
            } else if (cave[row][col] == 'S') {
                cave[row][col] = 'O'; 
                if (empty_row >= 0) {
                    cave[empty_row][col] = 'S';
                    --empty_row; 
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < N; ++i) {
        cout << cave[i] << endl;
    }

    return 0;
}
