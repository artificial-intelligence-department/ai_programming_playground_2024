#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool canSortAntiDiagonal(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> column_elements(n);


    for (int i = 0; i < n; ++i) {
        for (int row = 0; row < n; ++row) {
            column_elements[i].push_back(matrix[row][n - 1 - i]);
        }
        sort(column_elements[i].begin(), column_elements[i].end());
    }

    int prev_value = numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
        auto it = upper_bound(column_elements[i].begin(), column_elements[i].end(), prev_value);
        if (it == column_elements[i].end()) {
            return false;
        }
        prev_value = *it;
    }

    return true;
}

int main() {
    int n;
    cout << "Введіть розмір матриці N: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "Введіть елемент [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    if (canSortAntiDiagonal(matrix)) {
        cout << "Можливо розташувати елементи на бічній діагоналі у порядку зростання." << endl;
    } else {
        cout << "Неможливо розташувати елементи на бічній діагоналі у порядку зростання." << endl;
    }

    return 0;
}
