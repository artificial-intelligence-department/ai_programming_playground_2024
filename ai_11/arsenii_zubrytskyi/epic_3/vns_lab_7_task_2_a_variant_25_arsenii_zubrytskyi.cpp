#include <iostream>

void removeEvenRows(int**& arr, int& rows, int cols) {
    int newRowIndex = 0;
    for (int i = 0; i < rows; ++i) {
        if (i % 2 == 0) {
            delete[] arr[i];  // Видаляємо парний рядок
        } else {
            arr[newRowIndex++] = arr[i];  // Зміщуємо непарні рядки
        }
    }
    rows = newRowIndex;  // Оновлюємо кількість рядків
}

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows = 4, cols = 3;
    int** arr = new int*[rows];

    // Заповнюємо масив
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = i * cols + j;  // Наприклад, послідовність чисел
        }
    }

    std::cout << "Before removing even rows:" << std::endl;
    printArray(arr, rows, cols);

    removeEvenRows(arr, rows, cols);

    std::cout << "After removing even rows:" << std::endl;
    printArray(arr, rows, cols);

    // Очистка пам'яті
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
