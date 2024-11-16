#include <iostream>
using namespace std;

const int N = 4;

void rearrangeMatrix(int matrix[N][N]);
void moveMaxToTopRight(int matrix[N][N], int startRow, int startCol);
void swapRows(int matrix[N][N], int row1, int row2);
void swapColumns(int matrix[N][N], int col1, int col2);
bool checkDiagonal(int matrix[N][N]);

int main() {
    int matrix[N][N] = {
        {12, 0, 3, 5},
        {7, 15, 99, 10},
        {2, 5, 18, 4},
        {6, 11, 1, 1}
    };

    rearrangeMatrix(matrix);
    bool result = checkDiagonal(matrix);

    cout << "Matrix after rearrangement:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nIs the anti-diagonal descending: " << (result ? "Yes" : "No") << endl;
}

void rearrangeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        moveMaxToTopRight(matrix, N - 1 - i, N - 1 - i);
    }
}

void moveMaxToTopRight(int matrix[N][N], int startRow, int startCol) {
    int maxVal = matrix[startRow][startCol];
    int maxRow = startRow;
    int maxCol = startCol;

    for (int i = 0; i <= startRow; i++) {
        for (int j = 0; j <= startCol; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    if (maxRow != startRow) {
        swapRows(matrix, maxRow, startRow);
    }
    if (maxCol != startCol) {
        swapColumns(matrix, maxCol, startCol);
    }
}

void swapRows(int matrix[N][N], int row1, int row2) {
    for (int col = 0; col < N; col++) {
        int temp = matrix[row1][col];
        matrix[row1][col] = matrix[row2][col];
        matrix[row2][col] = temp;
    }
}

void swapColumns(int matrix[N][N], int col1, int col2) {
    for (int row = 0; row < N; row++) {
        int temp = matrix[row][col1];
        matrix[row][col1] = matrix[row][col2];
        matrix[row][col2] = temp;
    }
}

bool checkDiagonal(int matrix[N][N]) {
    for (int i = 0; i < N - 1; i++) {
        if (matrix[i][N - 1 - i] <= matrix[i + 1][N - 2 - i]) {
            return false;
        }
    }
    return true;
}
