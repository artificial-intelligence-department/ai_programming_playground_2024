#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char> > arr(N, vector<char>(M));

    for (int i = 0; i < N; i++) {
        string v;
        cin >> v;
        for (int j = 0; j < M; j++) {
            arr[i][j] = v[j];
        }
    }

    for (int j = 0; j < M; j++) { 
        for (int i = N - 2; i >= 0; i--) {
            if (arr[i][j] == 'S') { 
                int k = i;
                while (k + 1 < N && arr[k + 1][j] == 'O') {
                    k++;  
                }
                if (k != i && arr[k][j] != 'X') {
                    arr[k][j] = 'S'; 
                    arr[i][j] = 'O'; 
                }
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << arr[i][j];
        }
    }

    return 0;
}