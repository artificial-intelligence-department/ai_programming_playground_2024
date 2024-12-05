#include <iostream>
#include <vector>
using namespace std;

void Making_map(vector<vector<int>>& matrix, int x, int y);
int Find_min(vector<vector<int>>& matrix, int x, int y);

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    if (m == 1 && n == 1) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> matrix(n, vector<int>(m,0));

    Making_map(matrix, x, y);
    int minimum = Find_min(matrix, x, y);


    for (int i = 0; i < matrix[0].size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            matrix[j][i] += abs(minimum);
        }
    }
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}




void Making_map(vector<vector<int>>& matrix, int x, int y) {
    int k = 1;
    for (int i = y-2; i >= 0; i--) {
        matrix[x - 1][i] -= k++;
    }
    k = 1;
    for (int i = y; i < matrix[0].size(); i++) {
        matrix[x - 1][i] -= k++;
    }

    for (int i = 0; i < matrix[0].size(); i++) {
        k = 1;
        for (int j = x-2; j >= 0; j--){
            matrix[j][i] = matrix[x - 1][i] - k++;
        }  
    }
    for (int i = 0; i < matrix[0].size(); i++) {
        k = 1;
        for (int j = x; j < matrix.size(); j++){
            matrix[j][i] = matrix[x - 1][i] - k++;
        }
    }
}

int Find_min(vector<vector<int>>& matrix, int x, int y){
    int min = 2147483640;
    for (int i = 0; i < matrix[0].size(); i++){
        for (int j = 0; j < matrix.size(); j++){
            if (matrix[j][i] < min) min = matrix[j][i];
        }
    }
    return min;
}
