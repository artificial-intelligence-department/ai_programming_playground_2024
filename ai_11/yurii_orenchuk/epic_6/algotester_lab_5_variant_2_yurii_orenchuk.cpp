#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<char>> cave(N, vector<char>(M));

    char type;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> type;
            if (type == 'S' || type == 'O' || type == 'X') {
                cave[i][j] = type;
            }
        }
    }

    for (int j = 0; j < M; j++) {
        for (int i = N - 2; i >= 0; i--) {
            if (cave[i][j] == 'S') {
                int k = i; 
                while (k + 1 < N && cave[k + 1][j] == 'O') {
                    cave[k + 1][j] = 'S';
                    cave[k][j] = 'O';
                    k++;
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