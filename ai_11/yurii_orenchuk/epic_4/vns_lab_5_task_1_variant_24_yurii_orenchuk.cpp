#include <iostream>
using namespace std;

int max_diag(int (&matrix)[100][100], const int &n) {
    int max = 0;
    for (int k = 0; k < n; k++) {
        if (max < matrix[k][k])
            max = matrix[k][k];
    }
    return max;
}

int main() {
    int n;
    cout << "Введіть величину матриці: ";
    cin >> n;

    if (n > 100) {
        cout << "Занадто великий масив, спробуйте ще раз";
        return 1;
    }

    int matrix[100][100];

    cout << "Введіть елементи цієї матриці по рядках: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int MAX = max_diag(matrix, n);
    int counter = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > MAX) counter++;
        }
    }

    cout << "Кількість елементів множини, які більші за будь який елемент діагоналі: " << counter;

    return 0;
}