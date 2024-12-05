#include <iostream>
#include <algorithm>
using namespace std;

const int N = 4;

void rearrangeMatrix(int matrix[N][N]);
bool isDiagonalDescending(const int matrix[N][N]);

int main() {
    int matrix[N][N] = {
        {12, 8, 21, 8},
        {14, 5, 9, 10},
        {2, 18, 7, 4},
        {6, 11, 14, 26}
    };

    rearrangeMatrix(matrix);

    cout << "Matrix after rearrangement:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    if (isDiagonalDescending(matrix)) {
        cout << "\nThe anti-diagonal forms a descending sequence.\n";
    } else {
        cout << "\nThe anti-diagonal does not form a descending sequence.\n";
    }

    return 0;
}

void rearrangeMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        int maxVal = matrix[i][N - 1 - i];
        int maxRow = i, maxCol = N - 1 - i;

        for (int r = i; r < N; r++) {
            for (int c = i; c < N; c++) {
                if (matrix[r][c] > maxVal) {
                    maxVal = matrix[r][c];
                    maxRow = r;
                    maxCol = c;
                }
            }
        }

        if (maxRow != i) {
            swap(matrix[i], matrix[maxRow]);
        }

        if (maxCol != N - 1 - i) {
            for (int r = 0; r < N; r++) {
                swap(matrix[r][maxCol], matrix[r][N - 1 - i]);
            }
        }
    }
}

bool isDiagonalDescending(const int matrix[N][N]) {
    for (int i = 0; i < N - 1; i++) {
        if (matrix[i][N - 1 - i] <= matrix[i + 1][N - 2 - i]) {
            return false;
        }
    }
    return true;
}
