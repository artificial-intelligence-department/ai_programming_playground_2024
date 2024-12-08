#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int** createMatrix(int m, int n) {
    int** matrix = new int*[m];

    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }
    return matrix;
}

void fillRandom(int** matrix, int m, int n) {
    srand(time(0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void deleteMatrix(int** matrix, int m) {
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int m = 5, n = 5;
    int** A = createMatrix(m, n);
    fillRandom(A, m, n);
    printMatrix(A, m, n);
    deleteMatrix(A, m);

    return 0;
}