#include <iostream>
#include <utility>

using namespace std;

const int SIZE = 5;

void findMaxInColumns(int array[SIZE][SIZE], int result[SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        int maxElem = array[0][j];
        for (int i = 1; i < SIZE; i++) {
            if (array[i][j] > maxElem) {
                maxElem = array[i][j];
            }
        }
        result[j] = maxElem;
    }
}

void findMinInColumns(int array[SIZE][SIZE], int result[SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        int minElem = array[0][j];
        for (int i = 1; i < SIZE; i++) {
            if (array[i][j] < minElem) {
                minElem = array[i][j];
            }
        }
        result[j] = minElem;
    }
}

void findMaxInRows(int array[SIZE][SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int maxElem = array[i][0];
        for (int j = 1; j < SIZE; j++) {
            if (array[i][j] > maxElem) {
                maxElem = array[i][j];
            }
        }
        result[i] = maxElem;
    }
}

void findMinInRows(int array[SIZE][SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int minElem = array[i][0];
        for (int j = 1; j < SIZE; j++) {
            if (array[i][j] < minElem) {
                minElem = array[i][j];
            }
        }
        result[i] = minElem;
    }
}

void printMatrixRightDown(int array[SIZE][SIZE]) {
    for (int i = SIZE - 1; i >= 0; i--) {
        for (int j = SIZE - 1; j >= 0; j--) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printTransposedMatrix(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << array[j][i] << " ";
        }
        cout << endl;
    }
}

bool isSymmetric(int array[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (array[i][j] != array[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void findDiagonal(int array[SIZE][SIZE], int result[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        result[i] = array[i][i];
    }
}

void printArray(int array[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void printMatrix(int array[SIZE][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void printMirrorMatrix(int array[SIZE][SIZE], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }
    printMatrix(array, size);
}

pair<int, int> findElemInRows(int array[SIZE][SIZE], int size, int element) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] == element) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int findMin(int array[SIZE][SIZE], int size) {
    int min = array[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
        }
    }
    return min;
}

int findMax(int array[SIZE][SIZE], int size) {
    int max = array[0][0];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}

int findSum(int array[SIZE][SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += array[i][j];
        }
    }
    return sum;
}

double findAverage(int array[SIZE][SIZE], int size) {
    double sum = 0;
    double counter = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += array[i][j];
            counter++;
        }
    }
    return sum / counter;
}

void findEvenNumbers(int array[SIZE][SIZE], int size) {
    cout << "Парні числа в масиві: ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] % 2 == 0) {
                cout << array[i][j] << " ";
            }
        }
    }
    cout << endl;
}

void printMatrix(int rows, int cols, const int array[][6]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(const int array[5][6], int transposed[6][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            transposed[j][i] = array[i][j];
        }
    }
}

void printTransposedMatrix(int rows, int cols, const int array[][6], int transposed[][5]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = array[i][j];
        }
    }

    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int matrix[SIZE][SIZE] = {
        {3, 8, 1, 9, 2},
        {4, 2, 7, 5, 3},
        {9, 5, 2, 6, 1},
        {1, 3, 8, 7, 4},
        {6, 4, 3, 8, 9}
    };

    int result[SIZE];

    findMaxInColumns(matrix, result);
    cout << "Найбільші елементи в кожному стовпці: ";
    printArray(result);

    findMinInColumns(matrix, result);
    cout << "Найменші елементи в кожному стовпці: ";
    printArray(result);

    findMaxInRows(matrix, result);
    cout << "Найбільші елементи в кожному рядку: ";
    printArray(result);

    findMinInRows(matrix, result);
    cout << "Найменші елементи в кожному рядку: ";
    printArray(result);

    cout << "Масив з правого нижнього кута по рядках:" << endl;
    printMatrixRightDown(matrix);

    cout << "Масив дзеркальний відносно діагоналі:" << endl;
    printMirrorMatrix(matrix, SIZE);

    cout << "Чи є матриця симетричною: " << (isSymmetric(matrix) ? "Так" : "Ні") << endl;

    cout << "Мінімальний елемент матриці: " << findMin(matrix, SIZE) << endl;
    cout << "Максимальний елемент матриці: " << findMax(matrix, SIZE) << endl;

    cout << "Сума елементів матриці: " << findSum(matrix, SIZE) << endl;
    cout << "Середнє значення елементів матриці: " << findAverage(matrix, SIZE) << endl;

    findDiagonal(matrix, result);
    cout << "Діагональні елементи: ";
    printArray(result);

    findEvenNumbers(matrix, SIZE);

    int initialData2[5][6] = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30}
    };

    int transposed[6][5];

    cout << "Оригінальна матриця 5x6:" << endl;
    printMatrix(5, 6, initialData2);

    cout << "\nТранспонована матриця 6x5:" << endl;
    transposeMatrix(initialData2, transposed);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
