#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


int sumBelowDiagonal(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    int sum = 0;
    for (int i = 1; i < size; i++) { 
        for (int j = 0; j < i; j++) { 
            sum += matrix[i][j];
        }
    }
    return sum;
}


vector<vector<int>> generateMatrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}


void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(0)); 

    int n, size;
    cout << "Enter the number of matrices (n): ";
    cin >> n;
    cout << "Enter the size of square matrices: ";
    cin >> size;

    int maxSum = INT_MIN; 
    vector<vector<int>> maxMatrix; 

    for (int i = 0; i < n; i++) {
        cout << "\nMatrix " << i + 1 << ":" << endl;
        vector<vector<int>> matrix = generateMatrix(size);
        printMatrix(matrix);

        int currentSum = sumBelowDiagonal(matrix);
        cout << "Sum below main diagonal: " << currentSum << endl;

        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxMatrix = matrix; 
        }
    }

    cout << "\nMaximum sum below main diagonal: " << maxSum << endl;
    

    return 0;
}
