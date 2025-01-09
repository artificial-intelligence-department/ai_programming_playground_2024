#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    vector<char> answer;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char target = matrix[i][j];
            bool foundInRow = false, foundInCol = false;

            for (int col = 0; col < m; col++) {
                if (col != j && matrix[i][col] == target) {
                    foundInRow = true;
                    break; 
                }
            }

            for (int row = 0; row < n; row++) {
                if (row != i && matrix[row][j] == target) {
                    foundInCol = true;
                    break;
                }
            }

            if (!foundInRow && !foundInCol) {
                answer.push_back(matrix[i][j]);
                
            }
        }
    }

    for (int i = 0; i < answer.size(); i++) {
            cout << answer[i];
    }

    return 0;
}
