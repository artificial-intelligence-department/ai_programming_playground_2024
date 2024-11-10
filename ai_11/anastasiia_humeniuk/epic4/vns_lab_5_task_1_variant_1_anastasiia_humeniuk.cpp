#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 5;


bool isNegative(int row[], int cols) {
    for (int i = 0; i < cols; i++) {
        if (row[i] < 0)
        return true;
    }
    return false;
}

void remove(int arr[][COLS], int& rows) { 
    int writeIndex = 0;

    for (int i = 0; i < rows; i++) {
        if (!isNegative(arr[i], COLS)) { // true, якщо немає від'ємних
            for (int j = 0; j < COLS; j++) {
                arr[writeIndex][j] = arr[i][j];
            }
            writeIndex++;
        }
    }

    for (int i = writeIndex; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = 0;
        }
    }

    rows = writeIndex;
}


int main() {
    int arr[ROWS][COLS] = {
        {1, 2, 3, 4, 5},
        {-1, 2, -3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, -13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    int rows = ROWS;

    cout << "Початковий масив:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    remove(arr, rows);

    cout << "\nМасив після видалення рядків з від'ємними елементами:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}