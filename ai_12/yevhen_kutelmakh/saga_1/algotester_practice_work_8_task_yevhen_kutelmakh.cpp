#include <iostream>
#include <vector>
using namespace std;

int findMaxInColumn(const vector<vector<int>> &arr, int rows, int colIndex) {
    int maxInCol = arr[0][colIndex];
    for (int i = 1; i < rows; i++) {
        if (arr[i][colIndex] > maxInCol) {
            maxInCol = arr[i][colIndex];
        }
    }
    return maxInCol;
}

int findColumnWithMinMax(const vector<vector<int>> &arr, int rows, int cols) {
    int minMaxValue = 1001; 
    int bestColumn = -1;
    for (int j = 0; j < cols; j++) {
        int maxInCol = findMaxInColumn(arr, rows, j);
        if (maxInCol < minMaxValue) {
            minMaxValue = maxInCol;
            bestColumn = j;
        }
    }
    return bestColumn;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> arr(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
    int bestColumn = findColumnWithMinMax(arr, rows, cols);
    int result = findMaxInColumn(arr, rows, bestColumn);
    cout << result << endl;
    return 0;
}