#include <iostream>
#include <random>
using namespace std;

void MinMax(int* matrixPointers[5]);
void MatrixPrinting(int* matrixPointers[5]);

int main() {
    int matrix[5][5];
    srand(time(nullptr));

    cout << "Початкова матриця 5×5:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = (rand() % 90) + 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    int* matrixPoints[5];
    for (int i = 0; i < 5; i++) {
        int* matrixRow = matrix[i];
        matrixPoints[i] = matrixRow;
    }

    MinMax(matrixPoints);
    MatrixPrinting(matrixPoints);

    int matrix2[5][6];

    cout << "Початкова матриця 5×6:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            matrix2[i][j] = (rand() % 90) + 10;
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Транспонована матриця: " << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix2[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}

void MinMax(int* matrixPointers[5]) {
    int matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = matrixPointers[i][j];
        }
    }

    int arr[5];

    cout << "Найменші елементи стовпців: ";
    for (int i = 0; i < 5; i++) {
        int max = 0;
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] > max) max = matrix[j][i];
        }
        arr[i] = max;
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Найменші елементи стовпців: ";
    for (int i = 0; i < 5; i++) {
        int min = 100;
        for (int j = 0; j < 5; j++) {
            if (matrix[j][i] < min) min = matrix[j][i];
        }
        arr[i] = min;
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    cout << "Найменші елементи стрічок: ";
    for (int i = 0; i < 5; i++) {
        int max = 0;
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        arr[i] = max;
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Найменші елементи стрічок: ";
    for (int i = 0; i < 5; i++) {
        int min = 100;
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        arr[i] = min;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void MatrixPrinting(int* matrixPointers[5]) {
    int matrix[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = matrixPointers[i][j];
        }
    }

    cout << "Обернена матриця:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Повернута на 90° матриця: " << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j >= 0; j--) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Симетричність матриці: ";
    bool isSem = true;
    for (int i = 1; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                isSem = false;
                break;
            }
        }
    }

    if (isSem) cout << "True" << endl;
    else cout << "False" << endl;
    cout << endl;
}
