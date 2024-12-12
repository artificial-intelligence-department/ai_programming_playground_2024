#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


int main(){
    int N;
    fstream file("text.bat", fstream::binary | fstream::out);
    cin >> N;
    vector<std::vector<int>> sudoku(N);
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(const char& ch : str) sudoku[i].push_back(ch - '0');
    }
    int Q;
    cin >> Q;
    vector<vector<int>> results(Q);
    for(int i = 0; i < Q; i++){
        int row, col;
        cin >> row >> col;
        row--;
        col--;
        vector<int> vec(N);
        if(sudoku[row][col] == 0){
            for(int j = 0; j < N; j++){
            if(j == col || sudoku[row][j] == 0) continue;
                vec[sudoku[row][j] - 1] = sudoku[row][j]; 
            }
            for(int j = 0; j < N; j++){
                if(j == row || sudoku[j][col] == 0) continue;
                vec[sudoku[j][col] - 1] = sudoku[j][col]; 
            }

            for(int j = 0; j < N; j++){
                if(vec[j] != j + 1) results[i].push_back(j + 1);
            }           
        }
        else results[i].push_back(sudoku[row][col]);
        
    }

    for(vector<int>& v : results){
        cout << v.size() << endl;
        for(int& val : v) cout << val << " ";
        cout << endl << endl;
    }
    return 0;
}