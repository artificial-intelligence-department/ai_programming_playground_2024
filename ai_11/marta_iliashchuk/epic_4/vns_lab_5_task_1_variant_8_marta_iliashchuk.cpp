
#include <iostream>
using namespace std;

void printMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void transposeMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

bool isSymmetric(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false; 
            }
        }
    }
    return true; 
}

int main() {
    int m;
    cout << "Enter the size of the square matrix: ";
    cin >> m;

    // Allocate memory for the matrix
    int** matrix = new int*[m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new int[m];
    }

    cout << "Enter the matrix elements:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Original matrix:\n";
    printMatrix(matrix, m);

    if (isSymmetric(matrix, m)) {
        cout << "The matrix is symmetric." << endl;
    } else {
        cout << "The matrix is not symmetric." << endl;
    }

    transposeMatrix(matrix, m);
    cout << "Transposed matrix:\n";
    printMatrix(matrix, m);

    // Free the allocated memory
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}