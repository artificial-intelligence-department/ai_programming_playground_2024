#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для відновлення двовимірного масиву з одновимірного
void restoreTwoDimensionalArray(const vector<int>& oneDimArray, vector<vector<int>>& twoDimArray, int rows, int cols) {
    int index = 0;
    
    // Відновлення рядків
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            twoDimArray[i][j] = oneDimArray[index++];
        }
    }

    // Відновлення стовпців
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            twoDimArray[i][j] = oneDimArray[index++];
        }
    }
}

// Функція для виведення двовимірного масиву
void printTwoDimensionalArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    
    // Введення розмірності двовимірного масиву
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Одновимірний масив, який містить елементи з двовимірного масиву
    vector<int> oneDimArray(rows * cols * 2);  // Має бути вдвічі більше, оскільки спочатку йдуть рядки, потім стовпці

    cout << "Enter the elements of the one-dimensional array (rows first, then columns):" << endl;
    for (int i = 0; i < oneDimArray.size(); ++i) {
        cin >> oneDimArray[i];
    }

    // Створення двовимірного масиву для відновлення
    vector<vector<int>> twoDimArray(rows, vector<int>(cols));

    // Відновлення двовимірного масиву
    restoreTwoDimensionalArray(oneDimArray, twoDimArray, rows, cols);

    // Виведення відновленого двовимірного масиву
    cout << "The restored two-dimensional array is:" << endl;
    printTwoDimensionalArray(twoDimArray);

    return 0;
}
