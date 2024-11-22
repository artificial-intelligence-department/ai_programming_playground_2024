#include <iostream>
using namespace std;

void swapRowAndColumn(int matrix[][4], int size, int row, int col) {
    for (int i = 0; i < size; i++) {
        swap(matrix[row][i], matrix[i][col]); 
    }
}

void printMatrix(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    const int size = 4; 
    int matrix[size][size] = {
        {2, 1, 3, 4},
        {5, 2, 6, 7},
        {8, 9, 2, 1},
        {2, 4, 5, 6}
    };

    cout << "Original matrix:" << endl;
    printMatrix(matrix, size, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][0] == matrix[0][j]) { 
                swapRowAndColumn(matrix, size, i, j); 
            }
        }
    }

    cout << "\nMatrix after swapping rows and columns:" << endl;
    printMatrix(matrix, size, size);

    return 0;
}
