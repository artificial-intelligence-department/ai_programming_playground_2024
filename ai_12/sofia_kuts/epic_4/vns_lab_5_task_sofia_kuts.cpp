#include <iostream>
#include <vector>
using namespace std;

bool isUnique(int element, int rows, int cols, int** array) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (array[i][j] == element) {
                ++count;
                if (count > 1) return false;
            }
        }
    }
    return true;
}


int findMinUnique(int rows, int cols, int** array) {
    int minUnique = INT_MAX; 
    bool found = false;    

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (isUnique(array[i][j], rows, cols, array)) {
                found = true;
                if (array[i][j] < minUnique) {
                    minUnique = array[i][j];
                }
            }
        }
    }

    return found ? minUnique : -1; 
}

int main() {
    
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> array[i][j];
        }
    }

    int minUnique = findMinUnique(rows, cols, array);

    if (minUnique == -1) {
        cout << "No unique elements found in the array." << endl;
    } else {
        cout << "The minimum unique element is: " << minUnique << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}
