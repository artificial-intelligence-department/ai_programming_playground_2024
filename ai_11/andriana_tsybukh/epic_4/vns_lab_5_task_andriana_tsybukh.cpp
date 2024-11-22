#include <iostream>
#include <vector>

using namespace std;

// обчислення суми елементів у двовимірному масиві
int calculateSum(const vector<vector<int>>& matrix, int startCol, int endCol) {
    int sum = 0;

    if (startCol > endCol) {
        return 0;
    }

    for (const vector<int>& row : matrix) {
        for (int col = startCol; col <= endCol; ++col) {
            sum += row[col];
        }
    }
    return sum;
}

// перевірка наявності стовпця який розбиває масив
bool findSplittingColumn(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    if (cols < 3) {
        return false;
    }

    for (int col = 1; col < cols - 1; ++col) {
        int leftSum = calculateSum(matrix, 0, col - 1);    // ліва частина
        int rightSum = calculateSum(matrix, col + 1, cols - 1); // права частина
        cout << "Стовпець " << col << ": leftSum = " << leftSum << ", rightSum = " << rightSum << endl;

        if (leftSum > rightSum) {
            return true;
        }
    }

    return false;
}

int main() {
    int rows, cols;
    cout << "Введіть кількість рядків та стовпців матриці (через пробіл): ";
    cin >> rows >> cols;

    // введення матриці
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введіть елементи матриці:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (findSplittingColumn(matrix)) {
        cout << "Такий стовпець існує." << endl;
    } else {
        cout << "Такого стовпця не існує." << endl;
    }

    return 0;
}
