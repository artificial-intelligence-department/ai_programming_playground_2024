#include <iostream>
using namespace std;

// Функція для видалення рядків з індексів A до B
void deleteRows(int** matrix, int& rows, int cols, int A, int B) {
    int shift = B - A + 1; // Кількість рядків для видалення

    // Зсуваємо рядки, які залишились, вгору
    for (int i = A; i + shift < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = matrix[i + shift][j];
        }
    }

    // Заповнюємо останні рядки нулями
    for (int i = rows - shift; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }

    // Оновлюємо кількість рядків
    rows -= shift;
}

int main() {
    int rows = 6, cols = 5; // Початковий розмір матриці
    int A = 1, B = 3;       // Індекси рядків для видалення

    // Створення двовимірного динамічного масиву
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Ініціалізація матриці
    int counter = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = counter++;
        }
    }

    // Вивід початкової матриці
    cout << "Початкова матриця:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Видалення рядків з A до B
    deleteRows(matrix, rows, cols, A, B);

    // Вивід оновленої матриці
    cout << "\nОновлена матриця після видалення рядків:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Видалення динамічної пам'яті
    for (int i = 0; i < rows + (B - A + 1); ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
