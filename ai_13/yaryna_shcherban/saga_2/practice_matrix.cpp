#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int ROWS = 5;
const int COLS = 5;
const int ROWS_EXT = 5;
const int COLS_EXT = 6;

//  Функція для заповнення матриці випадковими числами 
void fillMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100; // Заповнення числами від 0 до 99
        }
    }
}

//  Функція для заповнення 5x6 матриці 
void fillMatrix(int matrix[ROWS_EXT][COLS_EXT], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

//  Функція для виведення матриці 
void printMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//  Функція для виведення 5x6 матриці 
void printMatrix(int matrix[ROWS_EXT][COLS_EXT], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//  Функція для транспонування матриці 5x6 
void transposeMatrix(int matrix[ROWS_EXT][COLS_EXT], int result[COLS_EXT][ROWS_EXT], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = matrix[i][j];
        }
    }
}

//  Додавання двох матриць 5x5 
void addMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//  Множення двох матриць 5x5 
void multiplyMatrices(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//  Пошук конкретного елементу 
bool findElement(int matrix[ROWS][COLS], int target) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == target) return true;
        }
    }
    return false;
}

//  Пошук максимального значення у матриці 
int findMax(int matrix[ROWS][COLS]) {
    int maxVal = matrix[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maxVal = max(maxVal, matrix[i][j]);
        }
    }
    return maxVal;
}

//  Пошук мінімального значення у матриці 
int findMin(int matrix[ROWS][COLS]) {
    int minVal = matrix[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            minVal = min(minVal, matrix[i][j]);
        }
    }
    return minVal;
}

// Пошук максимального значення в кожному стовпці
void findMaxInColumns(int matrix[5][5], int rows, int cols, int result[]) {
    for (int j = 0; j < cols; j++) {
        int maxVal = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        result[j] = maxVal;
    }
}

// Пошук мінімального значення в кожному стовпці
void findMinInColumns(int matrix[5][5], int rows, int cols, int result[]) {
    for (int j = 0; j < cols; j++) {
        int minVal = matrix[0][j];
        for (int i = 1; i < rows; i++) {
            minVal = min(minVal, matrix[i][j]);
        }
        result[j] = minVal;
    }
}

// Пошук максимального значення в кожному рядку
void findMaxInRows(int matrix[5][5], int rows, int cols, int result[]) {
    for (int i = 0; i < rows; i++) {
        int maxVal = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            maxVal = max(maxVal, matrix[i][j]);
        }
        result[i] = maxVal;
    }
}

// Пошук мінімального значення в кожному рядку
void findMinInRows(int matrix[5][5], int rows, int cols, int result[]) {
    for (int i = 0; i < rows; i++) {
        int minVal = matrix[i][0];
        for (int j = 1; j < cols; j++) {
            minVal = min(minVal, matrix[i][j]);
        }
        result[i] = minVal;
    }
}

// Пошук суми всіх елементів
int findSumOfElements(int matrix[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Пошук середнього значення
double findAverage(int matrix[ROWS][COLS]) {
    int sum = findSumOfElements(matrix);
    return static_cast<double>(sum) / (ROWS * COLS);
}

// Пошук діагональних елементів
void findDiagonalElements(int matrix[ROWS][COLS], int diagonal[ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        diagonal[i] = matrix[i][i];
    }
}

// Пошук рядка з максимальною сумою
int findRowWithMaxSum(int matrix[ROWS][COLS]) {
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < ROWS; i++) {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRow = i;
        }
    }
    return maxRow;
}

// Пошук числа, що повторюється найбільше
int findMostFrequentElement(int matrix[ROWS][COLS]) {
    const int MAX_VALUE = 100; 
    int frequency[MAX_VALUE] = {0};
    // Підрахунок частоти кожного числа
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            frequency[matrix[i][j]]++;
        }
    }
    // Знаходження числа з максимальною частотою
    int mostFrequent = 0;
    int maxCount = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mostFrequent = i;
        }
    }

    return mostFrequent;
}

// Пошук парних елементів
void findEvenElements(int matrix[ROWS][COLS], int evenElements[ROWS * COLS], int& count) {
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] % 2 == 0) {
                evenElements[count++] = matrix[i][j];
            }
        }
    }
}

// Поворот матриці на 90 градусів за годинниковою стрілкою
void rotateMatrix90(int matrix[5][5], int result[5][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[j][size - 1 - i] = matrix[i][j];
        }
    }
}

// Обертання матриці навколо її діагоналі
void transposeDiagonal(int matrix[5][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// Перевірка симетричності матриці
bool isSymmetric(int matrix[5][5], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

//  Обчислення визначника для 3x3 матриці 
int determinant(int matrix[3][3], int n) {
    int det = 0;
    if (n == 2) {
        return ((matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]));
    }
    for (int p = 0; p < n; ++p) {
        int temp[3][3], h = 0, k = 0;   // temp - мінор 
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == p) continue;
                temp[h][k++] = matrix[i][j];
                if (k == n - 1) { h++; k = 0; }
            }
        }                                                  // для (-1)^p
        det += matrix[0][p] * determinant(temp, n - 1) * ((p % 2 == 0) ? 1 : -1);
    }
    return det;
}

int main() {
    
//  Матриці 5x5 
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], resultMatrix[ROWS][COLS];

    fillMatrix(matrix1, ROWS, COLS);
    fillMatrix(matrix2, ROWS, COLS);

    cout << "Matrix 1:" << endl;
    printMatrix(matrix1, ROWS, COLS);

    cout << "Matrix 2:" << endl;
    printMatrix(matrix2, ROWS, COLS);

    //  Додавання двох матриць 
    addMatrices(matrix1, matrix2, resultMatrix);
    cout << "Sum of matrices:" << endl;
    printMatrix(resultMatrix, ROWS, COLS);

    //  Множення двох матриць 
    multiplyMatrices(matrix1, matrix2, resultMatrix);
    cout << "Product of matrices:" << endl;
    printMatrix(resultMatrix, ROWS, COLS);

    // Пошук конкретного елемента
    int target = 42;
    cout << "\nFinding element " << target << ": "
     << (findElement(matrix1, target) ? "Found" : "Not Found") << endl;

    //  Пошук максимуму та мінімуму 
    cout << "Maximum in Matrix 1: " << findMax(matrix1) << endl;
    cout << "Minimum in Matrix 1: " << findMin(matrix1) << endl;

    // Пошук максимальних і мінімальних елементів у стовпцях і рядках
    int maxInColumns[5], minInColumns[5], maxInRows[5], minInRows[5];
    findMaxInColumns(matrix1, 5, 5, maxInColumns);
    findMinInColumns(matrix1, 5, 5, minInColumns);
    findMaxInRows(matrix1, 5, 5, maxInRows);
    findMinInRows(matrix1, 5, 5, minInRows);

    cout << "\nMax in Columns: ";
    for (int val : maxInColumns) cout << val << " ";
    cout << "\nMin in Columns: ";
    for (int val : minInColumns) cout << val << " ";
    cout << "\nMax in Rows: ";
    for (int val : maxInRows) cout << val << " ";
    cout << "\nMin in Rows: ";
    for (int val : minInRows) cout << val << " ";
    cout << endl;

    // Поворот матриці на 90 градусів
    int rotatedMatrix[5][5];
    rotateMatrix90(matrix1, rotatedMatrix, 5);
    cout << "\nMatrix rotated by 90 degrees:" << endl;
    printMatrix(rotatedMatrix, 5, 5);

    transposeDiagonal(matrix1, 5);
    cout << "\nMatrix transposed along the diagonal:" << endl;
    printMatrix(matrix1, 5, 5);

    // Перевірка симетричності
    if (isSymmetric(matrix1, 5)) {
        cout << "\nThe matrix is symmetric." << endl;
    } else {
        cout << "\nThe matrix is not symmetric." << endl;
    }

    // Сума і середнє
    cout << "Sum of Elements: " << findSumOfElements(matrix1) << endl;
    cout << "Average of Elements: " << findAverage(matrix1) << endl;

    // Діагональні елементи
    int diagonal[ROWS];
    findDiagonalElements(matrix1, diagonal);
    cout << "Diagonal Elements: ";
    for (int i = 0; i < ROWS; i++) cout << diagonal[i] << " ";
    cout << endl;

    // Рядок з максимальною сумою
    cout << "Row with Maximum Sum: " << findRowWithMaxSum(matrix1) << endl;

    // Найчастіше число
    cout << "Most Frequent Element: " << findMostFrequentElement(matrix1) << endl;

    // Парні елементи
    int evenElements[ROWS * COLS];
    int evenCount;
    findEvenElements(matrix1, evenElements, evenCount);
    cout << "Even Elements: ";
    for (int i = 0; i < evenCount; i++) cout << evenElements[i] << " ";
    cout << endl;

    //  Визначник для матриці 3x3 
    int smallMatrix[3][3] = {{6, 1, 1}, {4, -2, 5}, {2, 8, 7}};
    cout << "Determinant of 3x3 matrix: " << determinant(smallMatrix, 3) << endl;

//  Матриця 5x6 
    int matrix5x6[ROWS_EXT][COLS_EXT];
    int transposedMatrix[COLS_EXT][ROWS_EXT];

    fillMatrix(matrix5x6, ROWS_EXT, COLS_EXT);
    cout << "Original 5x6 Matrix:" << endl;
    printMatrix(matrix5x6, ROWS_EXT, COLS_EXT);

    //  Транспонування матриці 
    transposeMatrix(matrix5x6, transposedMatrix, ROWS_EXT, COLS_EXT);
    cout << "Transposed 6x5 Matrix:" << endl;
    printMatrix(transposedMatrix, COLS_EXT, ROWS_EXT);

    return 0;
}