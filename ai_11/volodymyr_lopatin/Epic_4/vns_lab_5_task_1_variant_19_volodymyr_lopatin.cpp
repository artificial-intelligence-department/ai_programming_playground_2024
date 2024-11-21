#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canBuild(int n, const string& input) {
    if (input.size() != n*n) return false;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = input[(i * n) + j] - '0';
        }
    }

    for (int k = 1; k < n; ++k) {
        if (matrix[k][0] <= matrix[k-1][0]) return false;
    }
    return true;
}

int main() {
    string input;
    int n;
    cin >> input;
    cout << endl;
    cin >> n;
    if (canBuild(n, input) == true) {
        cout << "Можливо побудувати матрицю із зростаючим першим стовпцем.";
    } else {
        cout << "Неможливо побудувати матрицю із зростаючим першим стовпцем.";
    }
    return 0;
}