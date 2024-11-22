#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMinUnique(const vector<vector<int>>& matrix) {
    string elements = "";

    for (const auto& row : matrix) {
        for (int elem : row) {
            elements += to_string(elem) + " ";
        }
    }

    int minUnique = INT_MAX;
    for (const auto& row : matrix) {
        for (int elem : row) {
            string target = to_string(elem) + " ";
            size_t first = elements.find(target);
            size_t last = elements.rfind(target);
            if (first == last) {
                if (elem < minUnique) {
                    minUnique = elem;
                }
            }
        }
    }

    return (minUnique == INT_MAX) ? -1 : minUnique;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the elements of the matrix row by row:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int minUnique = findMinUnique(matrix);

    if (minUnique != -1) {
        cout << "The minimum unique element is: " << minUnique << endl;
    } else {
        cout << "No unique elements found." << endl;
    }

    return 0;
}
