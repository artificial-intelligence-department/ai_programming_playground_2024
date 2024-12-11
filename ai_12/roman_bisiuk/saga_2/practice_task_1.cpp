#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

void printMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int matrix[ROWS][COLS];

    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }

    cout << "Початкова матриця:" << endl;
    printMatrix(matrix, ROWS, COLS);

    int maxInColumns[COLS];
    for (int j = 0; j < COLS; j++) {
        int maxVal = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        maxInColumns[j] = maxVal;
    }

    cout << "Найбільші елементи стовпців:";
    for (int j = 0; j < COLS; j++) {
        cout << " " << maxInColumns[j];
    }
    cout << endl;

    int minInColumns[COLS];
    for (int j = 0; j < COLS; j++) {
        int minVal = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            minVal = min(minVal, matrix[i][j]);
        }
        minInColumns[j] = minVal;
    }

    cout << "Найменші елементи стовпців:";
    for (int j = 0; j < COLS; j++) {
        cout << " " << minInColumns[j];
    }
    cout << endl;

    int maxInRows[ROWS];
    for (int i = 0; i < ROWS; i++) {
        int maxVal = matrix[i][0];
        for (int j = 1; j < COLS; j++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        maxInRows[i] = maxVal;
    }

    cout << "Найбільші елементи рядків:";
    for (int i = 0; i < ROWS; i++) {
        cout << " " << maxInRows[i];
    }
    cout << endl;

    int minInRows[ROWS];
    for (int i = 0; i < ROWS; i++) {
        int minVal = matrix[i][0];
        for (int j = 1; j < COLS; j++) {
            minVal = min(minVal, matrix[i][j]);
        }
        minInRows[i] = minVal;
    }

    cout << "Найменші елементи рядків:";
    for (int i = 0; i < ROWS; i++) {
        cout << " " << minInRows[i];
    }
    cout << endl;

    cout << "Матриця з нижнього правого кута вверх і вниз по стовпцям:" << endl;
    for (int j = COLS - 1; j >= 0; j--) {
        for (int i = 0; i < ROWS; i++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    cout << "Матриця з нижнього правого кута зліва направо, зверху вниз:" << endl;
    for (int i = ROWS - 1; i >= 0; i--) {
        for (int j = 0; j < COLS; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    cout << "Матриця після обертання відносно головної діагоналі:" << endl;
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++) {
            cout << setw(4) << matrix[j][i];
        }
        cout << endl;
    }

    cout << "Матриця після повороту на 90 градусів:" << endl;
    for (int j = 0; j < COLS; j++) {
        for (int i = ROWS - 1; i >= 0; i--) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    bool isSymmetric = true;
    for (int i = 0; i < ROWS && isSymmetric; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
    }
    cout << "Матриця симетрична: " << (isSymmetric ? "Так" : "Ні") << endl;

    const int NEW_ROWS = 5;
    const int NEW_COLS = 6;
    int matrix5x6[NEW_ROWS][NEW_COLS];
    for (int i = 0; i < NEW_ROWS; i++) {
        for (int j = 0; j < NEW_COLS; j++) {
            matrix5x6[i][j] = rand() % 100 + 1;
        }
    }

    cout << "Матриця 5x6:" << endl;
    for (int i = 0; i < NEW_ROWS; i++) {
        for (int j = 0; j < NEW_COLS; j++) {
            cout << setw(4) << matrix5x6[i][j];
        }
        cout << endl;
    }

    cout << "Транспонована матриця 6x5:" << endl;
    for (int j = 0; j < NEW_COLS; j++) {
        for (int i = 0; i < NEW_ROWS; i++) {
            cout << setw(4) << matrix5x6[i][j];
        }
        cout << endl;
    }

    return 0;
}
