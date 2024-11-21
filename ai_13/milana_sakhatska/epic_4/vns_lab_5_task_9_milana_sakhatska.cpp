#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція для обчислення суми елементів нижче головної діагоналі
int sumBelowDiagonal(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    int sum = 0;
    for (int i = 1; i < size; i++) { // Починаємо з другого рядка (i=1)
        for (int j = 0; j < i; j++) { // Проходимо елементи лівіше головної діагоналі (j < i)
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Функція для генерації випадкової квадратної матриці
vector<vector<int>> generateMatrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100; // Генеруємо числа від 0 до 99
        }
    }
    return matrix;
}

// Функція для друку матриці
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int n, size;
    cout << "Enter the number of matrices (n): ";
    cin >> n;
    cout << "Enter the size of square matrices: ";
    cin >> size;

    int maxSum = INT_MIN; // Початкове значення для пошуку максимуму
    vector<vector<int>> maxMatrix; // Матриця з максимальною сумою

    for (int i = 0; i < n; i++) {
        cout << "\nMatrix " << i + 1 << ":" << endl;
        vector<vector<int>> matrix = generateMatrix(size);
        printMatrix(matrix);

        int currentSum = sumBelowDiagonal(matrix);
        cout << "Sum below main diagonal: " << currentSum << endl;

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxMatrix = matrix; // Зберігаємо матрицю з максимальною сумою
        }
    }

    cout << "\nMaximum sum below main diagonal: " << maxSum << endl;
    

    return 0;
}
