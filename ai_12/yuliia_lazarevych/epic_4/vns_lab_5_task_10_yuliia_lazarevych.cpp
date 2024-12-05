#include <iostream>
using namespace std;

//використовую функцію для перевірки наявності від’ємних елементів у рядку
//масив передається за посиланням як параметр, тому використовуємо & в ньому, що дозволить працювати з реальним масивом, а не з копією.
bool hasNegative(int (&arr)[5], int cols) {
    for (int i = 0; i < cols; i++) {
        if (arr[i] < 0) {
            return true;
        }
    }
    return false;
}

//використовую функцію для обробки масиву, яка замінює рядки з від’ємними елементами на нулі
//передаю масив за посиланням, щоб зміни в ньому були збережені, заміна рядка і його переміщення здійснюється в реальному масиві, а не в його копії.
void processArray(int (&arr)[5][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        if (hasNegative(arr[i], cols)) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = 0;
            }
            for (int k = i; k < rows - 1; k++) {
                for (int j = 0; j < cols; j++) {
                    arr[k][j] = arr[k + 1][j];
                }
            }
        }
    }
}

//використовую функцію для виведення масиву на екран
void printArray(int (&arr)[5][5], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // ініціалізую двовимірний масив
    int arr[5][5] = {
        {1, 2, 3, 4, -1},
        {6, 7, 8, 9, 10},
        {-1, -2, -3, -4, -5},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    int rows = 5;
    int cols = 5;

    cout << "Масив до обробки:" << endl;
    printArray(arr, rows, cols);

    processArray(arr, rows, cols);

    cout << "Масив після обробки:" << endl;
    printArray(arr, rows, cols);

    return 0;
}
