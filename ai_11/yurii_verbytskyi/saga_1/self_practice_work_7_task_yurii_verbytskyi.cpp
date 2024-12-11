#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter dimensions of matrix A (rows cols): ";
    cin >> rowsA >> colsA;
    cout << "Enter dimensions of matrix B (rows cols): ";
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Matrices cannot be multiplied (columns of A != rows of B)." << endl;
        return 1;
    }

    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }


    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> AB(rowsA, vector<int>(colsB, 0));
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resulting matrix AB:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << AB[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
