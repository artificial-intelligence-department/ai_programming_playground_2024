#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cin.ignore();

    vector<string> cave(N);
    for (int i = 0; i < N; i++) {
        getline(cin, cave[i]);
    }

    for (int col = 0; col < M; col++) {
        int emptyIndex = N - 1; 
        for (int row = N - 1; row >= 0; row--) {
            if (cave[row][col] == 'X') {
                emptyIndex = row - 1;
            } else if (cave[row][col] == 'S') {
                if (row != emptyIndex) {
                    cave[emptyIndex][col] = 'S';
                    cave[row][col] = 'O';
                }
                emptyIndex--;
            }
        }
    }

    for (string row : cave) {
        cout << row << endl;
    }

    return 0;
}
