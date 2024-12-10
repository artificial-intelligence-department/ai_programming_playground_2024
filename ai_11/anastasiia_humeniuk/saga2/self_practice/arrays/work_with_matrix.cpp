#include <iostream>
#include <algorithm> 

using namespace std;

const int N = 3;

void initializeMatrix(int matrix[N][N]) {
    cout << "Введіть елементи матриці (" << N << "x" << N << "):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrices(const int matrix1[N][N], const int matrix2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void transposeMatrix(const int matrix[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void findMaxMin(const int matrix[N][N], int& maxElem, int& minElem) {
    maxElem = matrix[0][0];
    minElem = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maxElem = max(maxElem, matrix[i][j]);
            minElem = min(minElem, matrix[i][j]);
        }
    }
}

int determinant(const int matrix[N][N]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    int matrix1[N][N], matrix2[N][N], result[N][N];

    cout << "Матриця 1:" << endl;
    initializeMatrix(matrix1);

    cout << "Матриця 2:" << endl;
    initializeMatrix(matrix2);

    cout << "\nМатриця 1:" << endl;
    printMatrix(matrix1);

    cout << "\nМатриця 2:" << endl;
    printMatrix(matrix2);

    addMatrices(matrix1, matrix2, result);
    cout << "\nСума матриць:" << endl;
    printMatrix(result);

    multiplyMatrices(matrix1, matrix2, result);
    cout << "\nДобуток матриць:" << endl;
    printMatrix(result);

    transposeMatrix(matrix1, result);
    cout << "\nТранспонована матриця 1:" << endl;
    printMatrix(result);

    int maxElem, minElem;
    findMaxMin(matrix1, maxElem, minElem);
    cout << "\nМаксимальний елемент у матриці 1: " << maxElem << endl;
    cout << "Мінімальний елемент у матриці 1: " << minElem << endl;

    cout << "\nДетермінант матриці 1: " << determinant(matrix1) << endl;
    
    return 0;
}
