#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void findSaddlePoints(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool saddlePointFound = false;

    for (int i = 0; i < rows; i++) {
        int minInRow = matrix[i][0];
        int colIndex = 0;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < minInRow) {
                minInRow = matrix[i][j];
                colIndex = j;
            }
        }

        bool isSaddlePoint = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndex] > minInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << "Сідлова точка знайдена: " << minInRow << " на позиції (" << i << ", " << colIndex << ")" << endl;
            saddlePointFound = true;
        }
    }
    for (int i = 0; i < rows; i++) {
        int maxInRow = matrix[i][0];
        int colIndex = 0;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] > maxInRow) {
                maxInRow = matrix[i][j];
                colIndex = j;
            }
        }

        bool isSaddlePoint = true;
        for (int k = 0; k < rows; k++) {
            if (matrix[k][colIndex] < maxInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint) {
            cout << "Сідлова точка знайдена: " << maxInRow << " на позиції (" << i << ", " << colIndex << ")" << endl;
            saddlePointFound = true;
        }
    }

    if (!saddlePointFound) {
        cout << "Сідлових точок не знайдено." << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Введіть кількість рядків і стовпців матриці: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    findSaddlePoints(matrix);

    return 0;
}
