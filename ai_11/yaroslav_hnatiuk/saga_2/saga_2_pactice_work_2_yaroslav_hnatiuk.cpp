#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

int const dim = 3;

int** createMatrix(int N);
int** productMatrix(int** matrixOne, int** matrixTwo);
void findMatrixModa(int** matrix);
int matrixDeterminant(int** matrix, int n);
void deleteMatrix(int** matrix);

int main() {
    cout << "Перша матриця:" << endl;
    int** matrixOne = createMatrix(1);

    cout << "Друга матриця:" << endl;
    int** matrixTwo = createMatrix(-1);

    cout << "Третя матриця (добуток двох інших):" << endl;
    int** matrixThree = productMatrix(matrixOne, matrixTwo);

    cout << "Значення яке зустрічається найчастіше:" << endl;
    findMatrixModa(matrixThree);

    cout << endl << "Визначник матриці: " << matrixDeterminant(matrixThree, dim);

    deleteMatrix(matrixOne);
    deleteMatrix(matrixTwo);
    deleteMatrix(matrixThree);

    return 0;
}

int** createMatrix(int N) {
    int** matrix = new int*[dim];
    srand(time(nullptr) + N);

    for (int i = 0; i < dim; i++) {
        matrix[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            matrix[i][j] = rand() % 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return matrix;
}

int** productMatrix(int** matrixOne, int** matrixTwo) {
    int** matrixThree = new int*[dim];

    for (int i = 0; i < dim; i++) {
        matrixThree[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            int element = 0;
            for (int k = 0; k < dim; k++) {
                element += matrixOne[i][k] * matrixTwo[k][j];
            }
            matrixThree[i][j] = element;
            cout << matrixThree[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return matrixThree;
}

void findMatrixModa(int** matrix) {
    int** modas = nullptr; 
    int size = 0;

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            bool newModa = true;

            for (int k = 0; k < size; k++) {
                if (matrix[i][j] == modas[k][0]) {
                    modas[k][1]++;
                    newModa = false;
                    break;
                }
            }

            if (newModa) {
                int** temp = new int*[size + 1];

                for (int k = 0; k < size; k++) {
                    temp[k] = new int[2];
                    temp[k][0] = modas[k][0];
                    temp[k][1] = modas[k][1];
                    delete[] modas[k]; 
                }
                delete[] modas; 

                temp[size] = new int[2];
                temp[size][0] = matrix[i][j];
                temp[size][1] = 1;

                modas = temp;
                size++;
            }
        }
    }

    sort(modas, modas + size, [](int* a, int* b) {return a[1] > b[1];});

    for (int i = 0; i < size; i++) {
        if (modas[i][1] == modas[0][1])
        cout << modas[i][0] << ": " << modas[i][1] << endl;
        else break;
    }

    for (int i = 0; i < size; i++) delete[] modas[i];
    delete[] modas;
}

int matrixDeterminant(int** matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    int det = 0;

    int** subMatrix = new int*[n - 1];
    for (int i = 0; i < n - 1; i++) {
        subMatrix[i] = new int[n - 1];
    }

    for (int x = 0; x < n; x++) {
        int sub_i = 0;
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                subMatrix[sub_i][sub_j] = matrix[i][j];
                sub_j++;
            }
            sub_i++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * matrixDeterminant(subMatrix, n - 1);
    }

    for (int i = 0; i < n - 1; i++) {
        delete[] subMatrix[i];
    }
    delete[] subMatrix;

    return det;
}

void deleteMatrix(int** matrix) {
    for (int i = 0; i < dim; i++) delete[] matrix[i];
    delete[] matrix;
}

