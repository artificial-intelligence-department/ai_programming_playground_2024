#include<iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char cave[n][m];
    int stop[m];
    for(int i = 0; i < m; i++){
        stop[i] = n;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cave[i][j];
        }
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(cave[i][j] == 'X'){
                stop[j] = i;
            }
            else if(cave[i][j] == 'S'){
                cave[i][j] = 'O';
                cave[stop[j] - 1][j] = 'S';
                stop[j]--;
            }
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cout << cave[i][j];
        }
        cout << endl;
    }
    return 0;
}