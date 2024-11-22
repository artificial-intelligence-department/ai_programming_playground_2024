#include <iostream>
#include <vector>

using namespace std;

bool isSaddlePoint(const vector<vector<int>>& matrix, int row, int col) {
    int n = matrix[0].size();
    int m = matrix[0].size();
    
    int element = matrix[row][col];
    
    // Перевірка, чи елемент найменший у своєму рядку та найбільший у своєму стовпці
    bool isMinInRow = true;
    for (int j = 0; j < m; j++) {
        if (matrix[row][j] < element) {
            isMinInRow = false;
            break;
        }
    }
    
    bool isMaxInCol = true;
    for (int i = 0; i < n; i++) {
        if (matrix[i][col] > element) {
            isMaxInCol = false;
            break;
        }
    }

    if (isMinInRow && isMaxInCol) {
        return true;
    }
    
    // Перевірка, чи елемент найбільший у своєму рядку та найменший у своєму стовпці
    bool isMaxInRow = true;
    for (int j = 0; j < m; j++) {
        if (matrix[row][j] > element) {
            isMaxInRow = false;
            break;
        }
    }

    bool isMinInCol = true;
    for (int i = 0; i < n; i++) {
        if (matrix[i][col] < element) {
            isMinInCol = false;
            break;
        }
    }

    return isMaxInRow && isMinInCol;
}

int main() {
    int n, m;
    cout << "Enter the number of rows (n): ";
    cin >> n;
    cout << "Enter the number of columns (m): ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Saddle points are:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isSaddlePoint(matrix, i, j)) {
                cout << "Saddle point at (" << i << ", " << j << ") with value " << matrix[i][j] << endl;
            }
        }
    }

    return 0;
}
