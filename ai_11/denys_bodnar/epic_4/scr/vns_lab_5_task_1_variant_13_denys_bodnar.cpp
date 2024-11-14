#include <iostream>
#include <vector>

using namespace std;

bool canSplitMatrix(const vector<vector<int>>& matrix, int& splitColumn) {
    int rows = matrix.size();
    if (rows == 0) return false;
    int cols = matrix[0].size();

    vector<int> colSums(cols, 0);
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            colSums[j] += matrix[i][j];
        }
    }

    int leftSum = 0;
    int totalSum = 0;
    for (int sum : colSums) {
        totalSum += sum;
    }

    for (int j = 0; j < cols - 1; ++j) {
        leftSum += colSums[j];
        int rightSum = totalSum - leftSum - colSums[j + 1];
        if (leftSum > rightSum) {
            splitColumn = j + 1;
            return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int splitColumn;
    if (canSplitMatrix(matrix, splitColumn)) {
        cout << "Стовпець " << splitColumn << " розбиває масив так, що ліва сума більша за праву." << endl;
        cout << "Тобто ми визначили, що сума першого стовбця більша за суму другого.";
    } else {
        cout << "Немає стовпця, який розбиває масив відповідно до умови." << endl;
    }

    return 0;
}
