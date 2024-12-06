#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Введіть к-сть рядків: ";
    cin >> rows;
    cout << "Введіть к-сть стовпців: ";
    cin >> cols;

    int matrix[100][100]; 

    cout << "Введіть всі елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Елемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Загальний вигляд матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    
    cout << "Сідлові точки:" << endl;
    bool foundSaddlePoint = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int current = matrix[i][j];

           
            bool isMinInRow = true;
            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] < current) {
                    isMinInRow = false;
                    break;
                }
            }

            bool isMaxInCol = true;
            for (int k = 0; k < rows; k++) {
                if (matrix[k][j] > current) {
                    isMaxInCol = false;
                    break;
                }
            }

            if (isMinInRow && isMaxInCol) {
                cout << "Елемент [" << i << "][" << j << "] = " << current << endl;
                foundSaddlePoint = true;
            }
        }
    }

    if (!foundSaddlePoint) {
        cout << "Сідлових точок не знайдено." << endl;
    }

    return 0;
}
