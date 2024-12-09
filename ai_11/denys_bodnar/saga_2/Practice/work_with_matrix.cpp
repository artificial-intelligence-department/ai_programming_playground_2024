#include <iostream>
#include <climits> // Для INT_MIN та INT_MAX

using namespace std;

const int ROWS = 5;
const int COLS = 5;
const int N = 5; // Для квадратної матриці


void findMinMaxInColumns(const int matrix[ROWS][COLS], int minCols[], int maxCols[]) { // Знаходження мінімуму і максимуму в рядках і стовпцях
    for (int j = 0; j < COLS; ++j) {
        minCols[j] = INT_MAX;
        maxCols[j] = INT_MIN;
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i][j] < minCols[j]) {
                minCols[j] = matrix[i][j];
            }
            if (matrix[i][j] > maxCols[j]) {
                maxCols[j] = matrix[i][j];
            }
        }
    }
}

void findMinMaxInRows(const int matrix[ROWS][COLS], int minRows[], int maxRows[]) {
    for (int i = 0; i < ROWS; ++i) {
        minRows[i] = INT_MAX;
        maxRows[i] = INT_MIN;
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] < minRows[i]) {
                minRows[i] = matrix[i][j];
            }
            if (matrix[i][j] > maxRows[i]) {
                maxRows[i] = matrix[i][j];
            }
        }
    }
}


void printMatrixBottomUp(const int matrix[ROWS][COLS]) { // Виведення матриці у зворотному порядку
    cout << "Матриця з нижнього правого кута вверх і вниз по стовпцях:\n";
    for (int col = COLS - 1; col >= 0; --col) {
        for (int row = ROWS - 1; row >= 0; --row) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

void printMatrixBottomLeftRight(const int matrix[ROWS][COLS]) {
    cout << "Матриця з нижнього правого кута зліва направо, зверху вниз:\n";
    for (int row = ROWS - 1; row >= 0; --row) {
        for (int col = COLS - 1; col >= 0; --col) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}


void rotateMatrix90(const int matrix[N][N], int rotated[N][N]) { // Обертання матриці на 90 градусів
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            rotated[j][N - 1 - i] = matrix[i][j];
        }
    }
}


bool isSymmetric(const int matrix[N][N]) { // Перевірка симетричності матриці
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}


void transposeMatrix(const int matrix[ROWS][COLS], int transposed[COLS][ROWS]) { // Транспонування матриці 5×6
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void printMatrix(const int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int matrix[ROWS][COLS] = {
        {3, 8, 4, 2, 6},
        {7, 1, 5, 9, 3},
        {4, 3, 6, 7, 8},
        {5, 2, 7, 8, 4},
        {9, 6, 8, 3, 1}
    };

    int minCols[COLS], maxCols[COLS];
    int minRows[ROWS], maxRows[ROWS];
    int rotated[N][N];
    int transposed[COLS][ROWS];

    // Знаходимо мінімум і максимум
    findMinMaxInColumns(matrix, minCols, maxCols);
    findMinMaxInRows(matrix, minRows, maxRows);

    cout << "Мінімуми у стовпцях: ";
    for (int i = 0; i < COLS; ++i) cout << minCols[i] << " ";
    cout << endl;

    cout << "Максимуми у стовпцях: ";
    for (int i = 0; i < COLS; ++i) cout << maxCols[i] << " ";
    cout << endl;

    cout << "Мінімуми у рядках: ";
    for (int i = 0; i < ROWS; ++i) cout << minRows[i] << " ";
    cout << endl;

    cout << "Максимуми у рядках: ";
    for (int i = 0; i < ROWS; ++i) cout << maxRows[i] << " ";
    cout << endl;

    // Виводимо матрицю у зворотному порядку
    printMatrixBottomUp(matrix);
    printMatrixBottomLeftRight(matrix);

    // Обертання матриці
    rotateMatrix90(matrix, rotated);
    cout << "Матриця після обертання на 90 градусів:\n";
    printMatrix(rotated);

    // Перевірка симетричності
    if (isSymmetric(matrix)) {
        cout << "Матриця симетрична.\n";
    } else {
        cout << "Матриця несиметрична.\n";
    }

    // Транспонування матриці
    transposeMatrix(matrix, transposed);
    cout << "Транспонована матриця:\n";
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
