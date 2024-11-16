#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> sudoku(N);
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(const char& ch : str) sudoku[i].push_back(ch - '0');
    }
    int Q;
    cin >> Q;
    vector<vector<int>> results(Q);
    for(int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        vector<int> vec(N);
        if(sudoku[x][y] == 0){
            for(int j = 0; j < N; j++){
                if(j == y || sudoku[x][j] == 0) continue;
                vec[sudoku[x][j] - 1] = sudoku[x][j]; 
            }
            for(int j = 0; j < N; j++){
                if(j == x || sudoku[j][y] == 0) continue;
                vec[sudoku[j][y] - 1] = sudoku[j][y]; 
            }

            for(int j = 0; j < N; j++){
                if(vec[j] != j + 1) results[i].push_back(j + 1);
            }       
        }
        else results[i].push_back(sudoku[x][y]);
    }
    for(vector<int>& v : results){
        cout << v.size() << endl;
        for(int& val : v) cout << val << " ";
        cout << endl << endl;
    }
    return 0;
}
