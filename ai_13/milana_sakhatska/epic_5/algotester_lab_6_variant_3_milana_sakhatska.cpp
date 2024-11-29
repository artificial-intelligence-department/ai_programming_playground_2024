#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> sudoku(N, vector<int>(N));  
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            sudoku[i][j] = str[j] - '0';
        }
    }

    int Q;
    cin >> Q;
    vector<vector<int>> results(Q);
    
    for (int i = 0; i < Q; i++) {
        int row, col;
        cin >> row >> col;
        row--; col--;  

        vector<bool> used(N, false);  
        vector<int>& res = results[i];
        
        if (sudoku[row][col] == 0) {
            
            for (int j = 0; j < N; j++) {
                if (sudoku[row][j] != 0) {
                    used[sudoku[row][j] - 1] = true;
                }
            }
            
            for (int j = 0; j < N; j++) {
                if (sudoku[j][col] != 0) {
                    used[sudoku[j][col] - 1] = true;
                }
            }

            for (int num = 1; num <= N; num++) {
                if (!used[num - 1]) {
                    res.push_back(num);
                }
            }
        } 

        else {
            res.push_back(sudoku[row][col]);
        }
    }

    for (const auto& res : results) {
        cout << res.size() << endl;
        for (int num : res) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
