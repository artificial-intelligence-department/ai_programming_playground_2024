#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> sumMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int rows = mat1.size();
    int cols = mat1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

vector<vector<int>> transposeMatrix(const vector<vector<int>>& mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    vector<vector<int>> transposed(cols, vector<int>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = mat[i][j];
        }
    }
    return transposed;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {

    vector<vector<int>> mat1 = {{1, 3, 5}, {7, 9, 11}, {13, 15, 17}};
    vector<vector<int>> mat2 = {{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};

    cout << "Matrix 1:" << endl;
    printMatrix(mat1);
    cout << "Matrix 2:" << endl;
    printMatrix(mat2);

    vector<vector<int>> summedMatrix = sumMatrices(mat1, mat2);
    cout << "Summed Matrix:" << endl;
    printMatrix(summedMatrix);

    vector<vector<int>> transposedMatrix = transposeMatrix(summedMatrix);
    cout << "Transposed Summed Matrix:" << endl;
    printMatrix(transposedMatrix);

    return 0;
}

