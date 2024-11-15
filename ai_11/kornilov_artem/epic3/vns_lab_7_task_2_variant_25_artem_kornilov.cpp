#include <iostream>
#include <vector>

using namespace std;


void deleteEvenRows(vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        if (i % 2 == 1) {
            matrix[i].clear();  
        }
    }
}


void deleteBetweenZeros(vector<int>& arr) {
    int firstZero = -1, secondZero = -1;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            if (firstZero == -1) {
                firstZero = i;
            } else {
                secondZero = i;
            }
             
        }

        if (firstZero != -1 && secondZero != -1) {
            arr.erase(arr.begin() + firstZero + 1, arr.begin() + secondZero);
        }

    }
    
   
   
}

int main() {
    
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    cout << "Original 2-dimensional arr: " << endl;
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    deleteEvenRows(matrix);
    cout << "\nWith lines deleted:" << endl;
    for (const auto& row : matrix) {
        if (!row.empty()) { 
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    
    vector<int> arr = {1, 2, 0, 3, 4, 0, 5, 6};
    cout << "\nOriginal arr: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    deleteBetweenZeros(arr);
    cout << "After deleting elements between two 0's: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
