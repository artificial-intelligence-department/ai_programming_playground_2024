#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<char>> cave(N, vector<char>(M));

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> cave[i][j];
        }
    }
    
    for (int j = 0; j < M; j++){
        for (int i = N - 2; i >= 0; i--){
            if (cave[i][j] == 'S'){
                int count = i;
                while(count + 1 < N && cave[count + 1][j] == 'O'){
                    count++;
                }
                if (count != i && cave[count][j] != 'X'){
                    cave[count][j] = 'S';
                    cave[i][j] = 'O';
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }

    return 0;
}