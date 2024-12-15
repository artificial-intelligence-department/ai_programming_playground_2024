#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

const int ROWS = 5;
const int COLS = 5;

void printMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout << "Original Matrix:" << endl;
    printMatrix(matrix, ROWS, COLS);

    // Найбільший елемент стовпців
    int maxCols[COLS];
    for (int j = 0; j < COLS; ++j) {
        maxCols[j] = matrix[0][j];
        for (int i = 1; i < ROWS; ++i) {
            maxCols[j] = max(maxCols[j], matrix[i][j]);
        }
    }
    
    cout << "Max elements in columns:" << endl;
    for (int j = 0; j < COLS; ++j) {
        cout << maxCols[j] << " ";
    }
    cout << endl;

    // Найменший елемент стовпців
    int minCols[COLS];
    for (int j = 0; j < COLS; ++j) {
        minCols[j] = matrix[0][j];
        for (int i = 1; i < ROWS; ++i) {
            minCols[j] = min(minCols[j], matrix[i][j]);
        }
    }

    cout << "Min elements in columns:" << endl;
    for (int j = 0; j < COLS; ++j) {
        cout << minCols[j] << " ";
    }
    cout << endl;

    // Найбільший елемент рядків
    int maxRows[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        maxRows[i] = matrix[i][0];
        for (int j = 1; j < COLS; ++j) {
            maxRows[i] = max(maxRows[i], matrix[i][j]);
        }
    }

    cout << "Max elements in rows:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << maxRows[i] << " ";
    }
    cout << endl;

    // Найменший елемент рядків
    int minRows[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        minRows[i] = matrix[i][0];
        for (int j = 1; j < COLS; ++j) {
            minRows[i] = min(minRows[i], matrix[i][j]);
        }
    }

    cout << "Min elements in rows:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        cout << minRows[i] << " ";
    }
    cout << endl;

    // Вивести матрицю з нижнього правого кута вверх і вниз по стовпцям
    cout << "Matrix from bottom-right upwards column-wise:" << endl;
    for (int j = COLS - 1; j >= 0; --j) {
        for (int i = ROWS - 1; i >= 0; --i) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    // Вивести матрицю з нижнього правого кута зліва направо, зверху вниз
    cout << "Matrix from bottom-right left-to-right row-wise:" << endl;
    for (int i = ROWS - 1; i >= 0; --i) {
        for (int j = COLS - 1; j >= 0; --j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    // Обернути значення матриці відносно головної діагоналі
    int transpose[COLS][ROWS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "Transposed Matrix:" << endl;
    printMatrix(transpose, COLS, ROWS);

    // Поворот матриці на 90 градусів
    int rotated[COLS][ROWS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            rotated[j][ROWS - 1 - i] = matrix[i][j];
        }
    }

    cout << "Matrix rotated by 90 degrees:" << endl;
    printMatrix(rotated, COLS, ROWS);

    // Перевірити чи матриця симетрична
    bool symmetric = true;
    for (int i = 0; i < ROWS && symmetric; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = false;
                break;
            }
        }
    }

    cout << "Matrix is " << (symmetric ? "symmetric" : "not symmetric") << "." << endl;

    return 0;
}
