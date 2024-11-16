#include <iostream>
using namespace std;

int main() {
    int width, height;

    cout << "Введіть кількість рядків матриці: ";
    cin >> height;

    cout << "Введіть кількість стовпців матриці: ";
    cin >> width;

    int matrix[100][100];
    cout << "Введіть елементи матриці: " << endl;
    for (int i = 0; i < height; i++) {
        for (int k = 0; k < width; k++) {
            cout << "Елемент [" << i + 1 << "][" << k + 1 << "]: ";
            cin >> matrix[i][k];
        }
    }

    cout << "Вихідна матриця: " << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Транспонована матриця: " << endl;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
