#include <iostream>
#include <random>
using namespace std;

void createMatrix(int** &array, int rows, int cols);
void displayMatrix(int** array, int rows, int cols);
void deleteRows(int** &array, int &rows, int firstRowToDelete, int secondRowToDelete);
void freeMatrix(int** &array, int rows);

int main() {
    int rows, cols, firstRowToDelete, secondRowToDelete;

    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    createMatrix(array, rows, cols);

    cout << "\nПочаткова матриця: \n";
    displayMatrix(array, rows, cols);

    do {
        cout << "\nВведіть діапазон рядків для видалення: ";
        cin >> firstRowToDelete >> secondRowToDelete;
    } while (firstRowToDelete < 1 || secondRowToDelete > rows || firstRowToDelete > secondRowToDelete);

    firstRowToDelete -= 1;
    secondRowToDelete -= 1;

    deleteRows(array, rows, firstRowToDelete, secondRowToDelete);

    cout << "\nМатриця після видалення рядків:\n";
    displayMatrix(array, rows, cols);

    freeMatrix(array, rows);

    return 0;
}


void createMatrix(int** &array, int rows, int cols) {
    srand(time(nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = (rand() % 90) + 10;
        }
    }
}

void displayMatrix(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteRows(int** &array, int &rows, int firstRowToDelete, int secondRowToDelete) {
    int shiftAmount = secondRowToDelete - firstRowToDelete + 1;
    for (int i = firstRowToDelete; i <= secondRowToDelete; i++) {
        delete[] array[i];
    }
    for (int i = firstRowToDelete; i < rows - shiftAmount; i++) {
        array[i] = array[i + shiftAmount];
    }
    rows -= shiftAmount;
}

void freeMatrix(int** &array, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
}

