#include <iostream>
using namespace std;

const int SIZE = 5;

void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
}

void swapRowAndColumn(int matrix[SIZE][SIZE], int rowIndex, int colIndex) {
    for (int i = 0; i < SIZE; ++i) {
        swap(matrix[rowIndex][i], matrix[i][colIndex]);
    }
}

int main() {
    int matrix[SIZE][SIZE] = {
        {1, 7, 3, 0, 8},
        {5, 6, 7, 8, 9},
        {3, 0, 1, 2, 3},
        {4, 4, 5, 6, 7},
        {2, 1, 0, 3, 4}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix);

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][0] == matrix[0][j]) {
                swapRowAndColumn(matrix, i, j);
            }
        }
    }

    cout << "Modified Matrix:" << endl;
    printMatrix(matrix);

    return 0;
}
