#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Використовуючи функції, розв’язати зазначене у варіанті завдання. Масив
повинен передаватися у функцію як параметр.

Елемент матриці є сідловою точкою, якщо він є найменшим у своєму рядку й
найбільшим у своєму стовпці (або навпаки: найбільшим у своєму рядку й
найменшим у своєму стовпці). Для заданої матриці визначити всі сідлові
точки.
*/

void findSaddlePoints(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool found = false;

    for (int i = 0; i < rows; i++) {
        // Шукаємо мінімальні елементи у рядку
        int minInRow = matrix[i][0];
        int colIndexMin = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                colIndexMin = j;
            }
        }
        
        // Перевіряємо чи цей елемент найбільший у стовпці
        bool isMaxInCol = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndexMin] > minInRow) {
                isMaxInCol = false;
                break;
            }
        }

        // Виводимо інформацію про сідлову точку якщо така є у рядку, і переходимо до наступного рядка
        if (isMaxInCol) {
            cout << "Saddle point is found at (" << i + 1 << ", " << colIndexMin + 1 << "): " << minInRow << "\n";
            found = true;
        }
    }

    // Проводимо ці ж операції, тільки шукаємо максимальні елементи для кожного рядку і перевіряємо їх 
    // на наявність сідлової точки 
    for (int i = 0; i < rows; i++) {
        int maxInRow = matrix[i][0];
        int colIndexMax = 0;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                colIndexMax = j;
            }
        }

        bool isMinInCol = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndexMax] < maxInRow) {
                isMinInCol = false;
                break;
            }
        }

        if (isMinInCol) {
            cout << "Saddle point is found at (" << i + 1 << ", " << colIndexMax + 1 << "): " << maxInRow << "\n";
            found = true;
        }
    }

    // Якщо не виявлено жодної сідлової точки, то виводимо цю інформацію
    if (!found) 
        cout << "No saddle points in this matrix";
}

int main() {
    int rows, cols;
    cout << "Enter amounts of rows and cols: ";
    cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        cout << "Enter " << i + 1 << " row: ";
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "This is your matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    findSaddlePoints(matrix);
    return 0;
}